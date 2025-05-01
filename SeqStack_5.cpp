#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100

typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SeqStack;

void Init(SeqStack &S) {
    S.top = -1;
}

bool Push(SeqStack &S, ElemType x) {
    if (S.top == MAXSIZE - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SeqStack &S, ElemType &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SeqStack &S, ElemType &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    return true;
}

bool isEmpty(SeqStack S) {
    return S.top == -1;
}

bool isFull(SeqStack S) {
    return S.top == MAXSIZE - 1;
}

int evaluatePostfix(const string &expr) {
    SeqStack S;
    Init(S);
    istringstream iss(expr);
    string token;
    int op1, op2, result;

    while (iss >> token) {
        if (isdigit(token[0])) {
            
            Push(S, stoi(token));
        } else {
            if (!Pop(S, op2)) return INT_MIN; 
            if (!Pop(S, op1)) return INT_MIN; 
            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) return INT_MIN; 
                    result = op1 / op2;
                    break;
                default: return INT_MIN; 
            }
            Push(S, result);
        }
    }

    if (!Pop(S, result)) return INT_MIN; 
    return result;
}

int main() {
    string expr1 = "8571-*+82/-";
    string expr2 = "9 3 1-3*+ 8 2/+";

    cout << "测试用例1的结果:" << evaluatePostfix(expr1) << endl;
    cout << "测试用例2的结果:" << evaluatePostfix(expr2) << endl;

    return 0;
}
