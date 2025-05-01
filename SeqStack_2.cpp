#include <iostream>
using namespace std;

typedef struct StackNode{
    char data;
    StackNode* next;
}StackNode, *LinkStack;

void Init(LinkStack& S){
    S = NULL;
}

bool isEmpty(LinkStack S){
    return S == NULL;
}

bool Push(LinkStack& S, char e){
    StackNode* newNode = new StackNode;
    newNode->data = e;
    newNode->next = S;
    S = newNode;
    return true;
}

bool Pop(LinkStack& S, char& e){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return false;
    }
    StackNode* p = S;
    e = p->data;
    S = p->next;
    delete p;
    return true;
}

bool GetTop(LinkStack S, char& e){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return false;
    }
    e = S->data;
    return true;
}

void Traverse(LinkStack S) {

    LinkStack reverseStack = NULL;
    LinkStack temp;
    while (S != NULL) {
        temp = S;
        S = S->next; 
        temp->next = reverseStack; 
        reverseStack = temp;
    }

    temp = reverseStack;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    while (reverseStack != NULL) {
        temp = reverseStack;
        reverseStack = reverseStack->next;
        temp->next = S; 
        S = temp; 
    }
}


void Clear(LinkStack &S) {
    char e;
    while (!isEmpty(S)) {
        Pop(S, e);
    }
}


void Destroy(LinkStack &S) {
    Clear(S);
}

int main() {
    LinkStack S;
    Init(S); 

    Push(S, 'a');
    Push(S, 'b');
    Push(S, 'c');

    cout << "链栈元素（从栈底到栈顶）: ";
    Traverse(S);
    cout << endl;

    char top;
    if (GetTop(S, top)) {
        cout << "栈顶元素: " << top << endl;
    }

    char e;
    while (Pop(S, e)) {
        cout << "出栈元素: " << e << endl;
    }

    Destroy(S);
    cout << "链栈已销毁" << endl;

    return 0;
}