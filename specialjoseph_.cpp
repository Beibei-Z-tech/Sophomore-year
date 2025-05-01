#include <iostream>
using namespace std;
struct LNode{
    int data;
    LNode* next;
};
LNode* baoshu(int data){
    LNode* newone;
    newone=new LNode;
    newone->data=data;
    newone->next=NULL;
    return newone;
}
int main(){
    int n,m;
    cout<<"请输入n:";
    cin>>n;
    cout<<"请输入m:";
    cin>>m;
    LNode* L=baoshu(1);
    LNode* r=L;
    for(int i=2;i<=n;++i){
        LNode* s=baoshu(i);
        r->next=s;
        r=s;
    }
    r->next=L;
    LNode* p;
    p=L;
    while(p!=L){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"依次退出的人的编号:";
    while(p->next!=p){
        for(int i=0;i<m-1;++i){
            r=p;
            p=p->next;
        }
        r->next=p->next; 
        cout<<p->data<<"";
        delete p;
        p=r->next;
    }
    cout<<endl;
    cout<<"约瑟夫是:"<<p->data<<endl;
    delete p; 
    return 0;
}
