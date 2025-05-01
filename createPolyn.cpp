#include <iostream>
#include <cmath>
using namespace std;

struct PolyNode {
    float coef; 
    int exp;   
    PolyNode *next;
    PolyNode(float c, int e) : coef(c), exp(e), next(nullptr) {}
};
PolyNode* CreatePolyn(int n) {
    PolyNode *head = new PolyNode(0, 0); 
    cout << "Enter terms as <coef> <exp>: " << endl;
    for (int i = 0; i < n; i++) {
        float coef;
        int exp;
        cin >> coef >> exp;
        PolyNode *node = new PolyNode(coef, exp);
        node->next = head->next;
        head->next = node;
    }
    return head;
}
PolyNode* OrderInsert(PolyNode *head, float coef, int exp) {
    PolyNode *node = new PolyNode(coef, exp);
    PolyNode *current = head;
    while (current->next != nullptr && current->next->exp > exp) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    return head;
}

// 多项式相加
PolyNode* Add(PolyNode *pa, PolyNode *pb) {
    PolyNode *result = new PolyNode(0, 0);
    PolyNode *ra = result;
    PolyNode *a = pa->next;
    PolyNode *b = pb->next;
    while (a != nullptr && b != nullptr) {
        if (a->exp == b->exp) {
            float sum = a->coef + b->coef;
            if (sum != 0) {
                ra->next = new PolyNode(sum, a->exp);
                ra = ra->next;
            }
            a = a->next;
            b = b->next;
        } else if (a->exp > b->exp) {
            ra->next = new PolyNode(a->coef, a->exp);
            ra = ra->next;
            a = a->next;
        } else {
            ra->next = new PolyNode(b->coef, b->exp);
            ra = ra->next;
            b = b->next;
        }
    }
    ra->next = (a != nullptr ? a : b);
    return result;
}
PolyNode* Sub(PolyNode *pa, PolyNode *pb) {
    PolyNode *b = pb->next;
    while (b != nullptr) {
        b->coef = -b->coef;
        b = b->next;
    }
    PolyNode *result = Add(pa, pb);
    b = pb->next;
    while (b != nullptr) {
        b->coef = -b->coef;
        b = b->next;
    }
    return result;
}

// 打印多项式
void Traverse(PolyNode *head) {
    PolyNode *current = head->next;
    bool isFirst = true;
    while (current != nullptr) {
        if (current->coef == 0) {
            current = current->next;
            continue;
        }
        if (!isFirst && current->coef > 0) cout << '+';
        if (current->coef == -1 && current->exp != 0) {
            cout << '-';
        } else if (current->coef != 1 || current->exp == 0) {
            cout << current->coef;
        }
        if (current->exp == 1) {
            cout << 'x';
        } else if (current->exp > 1) {
            cout << "x^" << current->exp;
        }
        isFirst = false;
        current = current->next;
    }
    if (isFirst) cout << '0'; 
    cout << endl;
}
PolyNode* Reverse(PolyNode *head) {
    PolyNode *prev = nullptr;
    PolyNode *current = head->next;
    PolyNode *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    return head;
}
float Evaluate(PolyNode *head, float x) {
    float result = 0;
    PolyNode *current = head->next;
    while (current != nullptr) {
        result += current->coef * pow(x, current->exp);
        current = current->next;
    }
    return result;
}
void DestroyPolyn(PolyNode *head) {
    PolyNode *current = head;
    while (current != nullptr) {
        PolyNode *temp = current;
        current = current->next;
        delete temp;
    }
}
int main() {
    PolyNode *A = new PolyNode(0, 0);
    A = OrderInsert(A, 7, 0);
    A = OrderInsert(A, 3, 1);
    A = OrderInsert(A, 9, 8);
    A = OrderInsert(A, 5, 17);

    PolyNode *B = new PolyNode(0, 0);
    B = OrderInsert(B, 8, 1);
    B = OrderInsert(B, 22, 7);
    B = OrderInsert(B, -9, 8);

    cout << "Polynomial A: ";
    Traverse(A);
    cout << "Polynomial B: ";
    Traverse(B);

    PolyNode *sum = Add(A, B);
    cout << "Sum of A and B: ";
    Traverse(sum);
    PolyNode *C = new PolyNode(0, 0);
    C = OrderInsert(C, 1, 0);
    C = OrderInsert(C, 1, 1);
    C = OrderInsert(C, 1, 2);

    PolyNode *D = new PolyNode(0, 0);
    D = OrderInsert(D, 1, 2);
    D = OrderInsert(D, -5, 3);

    cout << "Polynomial C: ";
    Traverse(C);
    cout << "Polynomial D: ";
    Traverse(D);

    PolyNode *diff = Sub(C, D);
    cout << "Difference of C and D: ";
    Traverse(diff);
    PolyNode *E = new PolyNode(0, 0);
    E = OrderInsert(E, -5, 0);
    E = OrderInsert(E, 2, 1);
    E = OrderInsert(E, 4, 6);
    E = OrderInsert(E, -10, 9);
    cout << "Polynomial E: ";
    Traverse(E);
    float x = 2;
    cout << "Value of Polynomial E at x = " << x << ": " << Evaluate(E, x) << endl;

    DestroyPolyn(A);
    DestroyPolyn(B);
    DestroyPolyn(C);
    DestroyPolyn(D);
    DestroyPolyn(E);
    DestroyPolyn(sum);
    DestroyPolyn(diff);

    return 0;
}