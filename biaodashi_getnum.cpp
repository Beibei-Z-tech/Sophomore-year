#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluateInfix(string expression) {
    stack<int> SNUM; // Stack for numbers
    stack<char> SOP; // Stack for operators

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            int value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            SNUM.push(value);
            i--; // Since the for loop also increments i
        } else if (expression[i] == '(') {
            SOP.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!SOP.empty() && SOP.top() != '(') {
                int val2 = SNUM.top(); SNUM.pop();
                int val1 = SNUM.top(); SNUM.pop();
                char op = SOP.top(); SOP.pop();
                SNUM.push(applyOp(val1, val2, op));
            }
            SOP.pop(); // Remove '(' from stack
        } else {
            while (!SOP.empty() && precedence(SOP.top()) >= precedence(expression[i])) {
                int val2 = SNUM.top(); SNUM.pop();
                int val1 = SNUM.top(); SNUM.pop();
                char op = SOP.top(); SOP.pop();
                SNUM.push(applyOp(val1, val2, op));
            }
            SOP.push(expression[i]);
        }
    }

    while (!SOP.empty()) {
        int val2 = SNUM.top(); SNUM.pop();
        int val1 = SNUM.top(); SNUM.pop();
        char op = SOP.top(); SOP.pop();
        SNUM.push(applyOp(val1, val2, op));
    }

    return SNUM.top();
}

int main() {
    string infixExp[] = {"3+2", "3*(2-1)", "9+(3-2*1)*3+8/2"};
    int n = sizeof(infixExp) / sizeof(infixExp[0]);
    for (int i = 0; i < n; ++i) {
        cout << "Infix: " << infixExp[i] << endl;
        cout << "Value: " << evaluateInfix(infixExp[i]) << endl << endl;
    }
    return 0;
}
