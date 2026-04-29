#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "traps.h"
#include "spinlock.h"

// Interrupt descriptor table (shared by all CPUs).
struct gatedesc idt[256];
extern uint vectors[];  // in vectors.S: array of 256 entry pointers
struct spinlock tickslock;
uint ticks;

void
tvinit(void)
{
  int i;

  for(i = 0; i < 256; i++)
    SETGATE(idt[i], 0, SEG_KCODE<<3, vectors[i], 0);
  SETGATE(idt[T_SYSCALL], 1, SEG_KCODE<<3, vectors[T_SYSCALL], DPL_USER);

  initlock(&tickslock, "time");
}

void
idtinit(void)
{
  lidt(idt, sizeof(idt));
}

void
trap(struct trapframe *tf)
{
  struct proc *curproc = myproc();

  if(tf->trapno == T_SYSCALL){
    if(curproc->killed)
      exit();
    curproc->tf = tf;
    syscall();
    if(curproc->killed)
      exit();
    return;
  }

  switch(tf->trapno){
  // --- Lazy Allocation 核心逻辑 ---
  case T_PGFLT: {
    uint va = rcr2();
    // 只要地址在 0 到 sz 之间，就是合法的 Lazy 区域
    // 删除了 va < PGROUNDDOWN(tf->esp) 的判断，防止误杀 sh 进程
    if(va < curproc->sz && va > 0){
      char *mem = kalloc();
      if(mem == 0){
        curproc->killed = 1;
        break;
      }
      memset(mem, 0, PGSIZE);
      if(mappages(curproc->pgdir, (char*)PGROUNDDOWN(va), PGSIZE, V2P(mem), PTE_W|PTE_U) < 0){
        kfree(mem);
        curproc->killed = 1;
      }
    } else {
      // 真正越界访问时才杀掉进程
      curproc->killed = 1;
    }
    break;
  }

  case T_IRQ0 + IRQ_TIMER:
    if(cpuid() == 0){
      acquire(&tickslock);
      ticks++;
      wakeup(&ticks);
      release(&tickslock);
    }
    lapiceoi();
    break;
  case T_IRQ0 + IRQ_IDE:
    ideintr();
    lapiceoi();
    break;
  case T_IRQ0 + IRQ_IDE+1:
    break;
  case T_IRQ0 + IRQ_KBD:
    kbdintr();
    lapiceoi();
    break;
  case T_IRQ0 + IRQ_COM1:
    uartintr();
    lapiceoi();
    break;
  case T_IRQ0 + 7:
  case T_IRQ0 + IRQ_SPURIOUS:
    lapiceoi();
    break;

  default:
    if(curproc == 0 || (tf->cs&3) == 0){
      // 内核错误则 panic
      panic("trap");
    }
    // 用户态错误则杀掉
    curproc->killed = 1;
  }

  // 检查进程是否被标记为 killed
  if(curproc && curproc->killed && (tf->cs&3) == DPL_USER)
    exit();

  // 时间片轮转
  if(curproc && curproc->state == RUNNING &&
     tf->trapno == T_IRQ0+IRQ_TIMER)
    yield();

  if(curproc && curproc->killed && (tf->cs&3) == DPL_USER)
    exit();
}
