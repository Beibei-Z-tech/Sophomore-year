#include <iostream>
using namespace std;
enum Status{OK, ERROR};

typedef int ElemType;
typedef struct Lnode{
    ElemType data;
    Lnode* next;
}Lnode,*LinkList;

Status InitList(LinkList &L){
    L= new Lnode;
    L->next=NULL;
    return OK;
}

Status InsertList(LinkList &L,int i, ElemType e){
    Lnode *p=L;
    Lnode *s;
    s=new Lnode;
    int j=0;
    while (p&&j<i-1){
        p=p->next;
        j++;
    }
    if(!p){
        return ERROR;
    }
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status TraverseList(LinkList L){
    Lnode *p=L->next;
    while (p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return OK;
}

Status LocateElem(LinkList L, int i){
    int j = 0;
    Lnode *p = L;
    while (p && j < i - 1){
        p = p->next;
        j++;
    }
    if(p) {
        cout << p->data << endl;
    } else {
        cout << "没有该元素" << endl;
    }
    return OK;
}


Status DeleteList(LinkList &L, int i){
    Lnode *p,*q;
    p=L;
    int j=0;
    while (p&&j<i-1){
        p=p->next;
        j++;
    }
    if (!p || !(p->next) || i < 1) { // 添加了检查
        cout << "没有该元素" << endl;
        return ERROR;}
    q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}

int main(){
    LinkList L;
    InitList (L);
    for(int i=1;i<=5;i++)
        InsertList(L,i,i);
    InsertList(L,6,6);
    InsertList(L,3,33);
    TraverseList(L);
    LocateElem(L,5);
    LocateElem(L,6);
    LocateElem(L,3);
    LocateElem(L,12);
    DeleteList(L,1);
    DeleteList(L,5);
    DeleteList(L,3);
    DeleteList(L,20);
    TraverseList(L);
    return 0;
}