#include <iostream>
using namespace std;
enum Status {ERROR, OK};

typedef int Elemtype;
typedef struct Lnode{
    Elemtype data;
    struct Lnode *next;
}Lnode, *LinkList;

Status InitList(LinkList &L){
    L= new Lnode;
    L->next=NULL;
    return OK;
}

void CreateList_H(LinkList &L, int n){
    L=new Lnode;
    L->next =NULL;
    Lnode *p;
    for(int i=n;i>0;--i){
        p=new Lnode;
        cin>>p->data;
        p->next=L->next;
        L->next=p;
        }
}

void ListTraverse(LinkList L){
    Lnode *p;
    p=L->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int ListLength(LinkList L){
    int len=0;
    Lnode *p;
    p=L->next;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

int main(){
    LinkList L;
    InitList(L);
    CreateList_H(L,5);
    ListTraverse(L);
    cout<<"Length of the list is "<<ListLength(L)<<endl;
    return 0;
}