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

void DecimalToBase(SeqStack &S, int num, int base) {

    if (num == 0) {
        cout << "0" << endl;
        return;
    }
    
    while (num > 0) {
        int remainder = num % base;
        Push(S, remainder);
        num /= base;
    }
    
    cout << "转换结果（" << base << "进制）: ";
    while (!isEmpty(S)) {
        Pop(S, num);
        char digit = (num < 10) ? (num + '0') : (num - 10 + 'A');
        cout << digit;
    }
    cout << endl;
}

int main() {
    SeqStack S;
    Init(S); 

    int decimalNumber, base;
    
    cout << "请输入一个十进制数: ";
    cin >> decimalNumber;
    cout << "请输入要转换的进制: ";
    cin >> base;
    
    DecimalToBase(S, decimalNumber, base);

    return 0;
}