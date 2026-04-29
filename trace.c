#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int
main(int argc, char *argv[])
{
  int i;
  char *nargv[MAXARG];

  // 参数检查：trace 后面至少要跟 [mask] 和 [command]
  if(argc < 3 || (argv[1][0] < '0' || argv[1][0] > '9')){
    printf(2, "Usage: %s mask command [args]\n", argv[0]);
    exit();
  }

  // 1. 调用你刚写的系统调用，设置掩码
  if (trace(atoi(argv[1])) < 0) {
    printf(2, "%s: trace failed\n", argv[0]);
    exit();
  }

  // 2. 准备要执行的子命令及其参数
  for(i = 2; i < argc && i < MAXARG; i++){
    nargv[i-2] = argv[i];
  }

  // 3. 执行子命令
  // 一旦 exec 成功，当前进程的内容会被新程序替换，但 tracing_mask 会保留
  exec(nargv[0], nargv);
  
  printf(2, "exec %s failed\n", nargv[0]);
  exit();
}
