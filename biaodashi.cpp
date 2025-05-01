#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {

        if (isdigit(infix[i]))
            postfix += infix[i];

        else if (infix[i] == '(')
            s.push(infix[i]);

        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    
        else if (isOperator(infix[i])) {
            
            while (!s.empty() && getPrecedence(infix[i]) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]); 
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExp[] = {"3+2", "3*(2-1)", "9+(3-2*1)*3+8/2"};
    int n = sizeof(infixExp) / sizeof(infixExp[0]);
    for (int i = 0; i < n; ++i) {
        cout << "Infix: " << infixExp[i] << endl;
        cout << "Postfix: " << infixToPostfix(infixExp[i]) << endl << endl;
    }
    return 0;
}



