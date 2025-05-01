#include <iostream>
#include <string>
using namespace std;

typedef struct StackNode {
    char data;
    StackNode* next;
} StackNode, *LinkStack;

void Init(LinkStack& S) {
    S = NULL;
}

bool isEmpty(LinkStack S) {
    return S == NULL;
}

bool Push(LinkStack& S, char e) {
    StackNode* newNode = new StackNode;
    newNode->data = e;
    newNode->next = S;
    S = newNode;
    return true;
}

bool Pop(LinkStack& S, char& e) {
    if (isEmpty(S)) {
        return false;
    }
    StackNode* p = S;
    e = p->data;
    S = p->next;
    delete p;
    return true;
}

bool isLeft(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isRight(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool isMatch(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

bool checkBrackets(const string& expr) {
    LinkStack S;
    Init(S);

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (isLeft(c)) {
            Push(S, c);
        } else if (isRight(c)) {
            if (isEmpty(S)) {
                return false; 
            }
            char left;
            Pop(S, left);
            if (!isMatch(left, c)) {
                return false; 
            }
        }
    }

    return isEmpty(S);
}

int main() {
    string expr1 = "{[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}";
    string expr2 = "{{[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}";
    string expr3 = "{[(4+5)*(5-8)+2]-[(9-8))*(5-2)]}";
    string expr4 = "}[(4+5)";

    cout << "判断实例1:" << (checkBrackets(expr1) ? "匹配" : "不匹配") << endl;
    cout << "判断实例2:" << (checkBrackets(expr2) ? "匹配" : "不匹配") << endl;
    cout << "判断实例3:" << (checkBrackets(expr3) ? "匹配" : "不匹配") << endl;
    cout << "判断实例4:" << (checkBrackets(expr4) ? "匹配" : "不匹配") << endl;

    return 0;
}
