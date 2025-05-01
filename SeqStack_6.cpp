#include <iostream>
#include <string>
using namespace std;

typedef struct StackNode {
    char data;
    int position;
    StackNode* next;
} StackNode, *LinkStack;

void Init(LinkStack& S) {
    S = NULL;
}

bool isEmpty(LinkStack S) {
    return S == NULL;
}

bool Push(LinkStack& S, char e, int pos) {
    StackNode* newNode = new StackNode;
    newNode->data = e;
    newNode->position = pos;
    newNode->next = S;
    S = newNode;
    return true;
}

bool Pop(LinkStack& S, char& e, int& pos) {
    if (isEmpty(S)) {
        return false;
    }
    StackNode* p = S;
    e = p->data;
    pos = p->position;
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
            Push(S, c, i);
        } else if (isRight(c)) {
            if (isEmpty(S)) {
                cout << "不匹配：没有找到匹配的左括号，右括号位置 " << i << endl;
                return false; 
            }
            char left;
            int leftPos;
            Pop(S, left, leftPos);
            if (!isMatch(left, c)) {
                cout << "不匹配：左括号 '" << left << "' 位置 " << leftPos << " 与右括号 '" << c << "' 位置 " << i << " 不匹配" << endl;
                return false; 
            }
        }
    }

    if (!isEmpty(S)) {
        char left;
        int leftPos;
        Pop(S, left, leftPos);
        cout << "不匹配：左括号 '" << left << "' 位置 " << leftPos << " 没有找到匹配的右括号" << endl;
        return false; 
    }

    return true; 
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
