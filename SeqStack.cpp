#include<iostream>
using namespace std;
typedef int ElemType;
#define MAXSIZE 100

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

void Init (SeqStack &S){
    S.top=-1;
}

bool Push(SeqStack &S, ElemType x){
    if (S.top==MAXSIZE-1){
        return false;
    }
    S.data[++S.top]=x;
    return true;
}

bool Pop(SeqStack &S, ElemType &x){
    if (S.top==-1){
        return false;
    }
    x=S.data[S.top--];
    return true;
}

bool GetTop(SeqStack &S, ElemType &x){
    if (S.top==-1){
        return false;
    }
    x=S.data[S.top];
    return true;
}

void Traverse(SeqStack S){
    for (int i=S.top; i>=0; --i){
        cout<<S.data[i]<<" ";    
        }
        cout<<endl;
}

void Clear(SeqStack &S){
    S.top=-1;
}

void Destroy(SeqStack &S){
    S.top=-1;
}

bool isEmpty(SeqStack S){
    return S.top==-1;
}

bool isFull(SeqStack S){
    return S.top==MAXSIZE -1;
}

int main(){
    SeqStack S;
    ElemType x;
    Init(S);
    cout<<"栈已初始化"<<endl;
    for (int i=0;i<10; ++i){
        if (!Push(S,i)){
            cout<<"栈已满"<<endl;
            break;
        }
    }
    cout<<"已入栈"<<endl;
    cout<<"栈内元素：";
    Traverse(S);
    if (GetTop(S,x)){
        cout<<"栈顶元素为："<<x<<endl;
    }else{
        cout<<"栈为空"<<endl;
    }
    cout<<"出栈操作:";
    while(!isEmpty(S)){
        if (Pop(S,x)){
            cout<<x<<" ";
        }else{
            cout<<"栈为空"<<endl;
            break;
        }
    }
    cout<<endl;
    Clear(S);
    cout<<"栈已清空"<<endl;
    Destroy(S);
    cout<<"栈已销毁"<<endl;
    cout<<"栈是否为空："<<(isEmpty(S)?"是":"否")<<endl;
    cout<<"栈是否已满："<<(isFull(S)?"是":"否")<<endl;
    return 0;
}