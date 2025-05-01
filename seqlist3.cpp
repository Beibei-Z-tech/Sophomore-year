#include <iostream>
using namespace std;

struct SeqListNode {
    int data;
    SeqListNode* next;
};

struct ListNode {
    int data;
    ListNode* next;
};

SeqListNode* createSeqList() {
    SeqListNode* seqList = new SeqListNode[6]; 
    for (int i = 1; i <= 5; ++i) {
        seqList[i].data = i;
        seqList[i].next = &seqList[i + 1];
    }
    return &seqList[0];
}

ListNode* createList_H(SeqListNode* seqList) {
    ListNode* list = new ListNode[6]; 
    ListNode* head = &list[0];
    head->next = nullptr;
    for (int i = 5; i >= 1; --i) {
        list[i].data = seqList[i].data;
        list[i].next = head->next;
        head->next = &list[i];
    }
    return head;
}

void traverseList(ListNode* head) {
    ListNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    SeqListNode* seqList = createSeqList();
    ListNode* list = createList_H(seqList);
    traverseList(list);
    delete[] seqList;
    delete[] list;
    return 0;
}
