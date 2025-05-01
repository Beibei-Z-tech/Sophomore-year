#include <iostream>
#include <fstream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

void InitList(ListNode*& L) {
    L=new ListNode;
    L->next = nullptr;
}

void CreateList_H(ListNode*& L, ifstream& in) {
    InitList(L);
    int data;
    while (in >> data) {
        ListNode* newNode = new ListNode;
        newNode->data = data;
        newNode->next = L->next;
        L->next = newNode;
    }
}

void CreateList_R(ListNode*& L, ifstream& in) {
    InitList(L);
    ListNode* rear = L; 
    int data;
    while (in >> data) { 
        ListNode* newNode = new ListNode;
        newNode->data = data;
        rear->next = newNode;
        rear = newNode;
    }
}

void ListTraverse(ListNode* L) {
    ListNode* p = L->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int ListLength(ListNode* L) {
    int length = 0;
    ListNode* p = L->next;
    while (p != nullptr) {
        ++length;
        p = p->next;
    }
    return length;
}

int main() {

    ListNode* A = nullptr;
    ifstream inA("input_A.txt");
    CreateList_H(A, inA);
    inA.close();
    cout << "单链表A: ";
    ListTraverse(A);
    cout << "A的表长: " << ListLength(A) << endl;

    ListNode* B = nullptr;
    ifstream inB("input_B.txt");
    CreateList_R(B, inB);
    inB.close();
    cout << "单链表B: ";
    ListTraverse(B);
    cout << "B的表长: " << ListLength(B) << endl;

    ListNode* L = nullptr;
    InitList(L);
    delete A;
    delete B;
    delete L;

    return 0;
}
