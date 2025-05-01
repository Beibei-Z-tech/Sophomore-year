#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* createList() {
    ListNode* head = new ListNode;
    head->next = nullptr;
    return head;
}

bool insertNode(ListNode* head, int i, int e) {
    if (i < 1) return false;
    ListNode* p = head;
    int pos = 0;
    while (p != nullptr && pos < i - 1) {
        p = p->next;
        ++pos;
    }
    if (p == nullptr) return false;
    ListNode* newNode = new ListNode;
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

bool deleteNode(ListNode* head, int i, int& e) {
    if (i < 1 || head->next == nullptr) return false;
    ListNode* p = head;
    int pos = 0;
    while (p->next != nullptr && pos < i - 1) {
        p = p->next;
        ++pos;
    }
    if (p->next == nullptr || pos < i - 1) return false;
    ListNode* delNode = p->next;
    p->next = delNode->next;
    e = delNode->data;
    delete delNode;
    return true;
}

int findNode(ListNode* head, int e) {
    ListNode* p = head->next;
    int pos = 1;
    while (p != nullptr) {
        if (p->data == e) return pos;
        p = p->next;
        ++pos;
    }
    return -1;
}

void traverseList(ListNode* head) {
    ListNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void destroyList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        ListNode* q = p;
        p = p->next;
        delete q;
    }
}

int main() {
    ListNode* list = createList();

    for (int i = 1; i <= 5; ++i) {
        insertNode(list, i, i);
    }
    cout << "插入元素后链表: ";
    traverseList(list);

    if (!insertNode(list, 6, 6)) {
        cout << "无法在序号6位置插入元素6" << endl;
    }
    if (!insertNode(list, 3, 33)) {
        cout << "无法在序号3位置插入元素33" << endl;
    }
    cout << "插入元素后链表: ";
    traverseList(list);

    int elements[] = {5, 6, 3, 12};
    int size = sizeof(elements) / sizeof(elements[0]);
    for (int j = 0; j < size; ++j) {
        int e = elements[j];
        int pos = findNode(list, e);
        if (pos != -1) {
            cout << "查询元素" << e << "的编号: " << pos << endl;
        } else {
            cout << "没有元素" << e << endl;
        }
    }

    int deletedData;
    int indices[] = {1, 5, 3, 20};
    size = sizeof(indices) / sizeof(indices[0]);
    for (int j = 0; j < size; ++j) {
        int i = indices[j];
        if (deleteNode(list, i, deletedData)) {
            cout << "删除序号" << i << "位置的元素: " << deletedData << endl;
        } else {
            cout << "无法删除序号" << i << "位置的元素" << endl;
        }
    }
    cout << "删除元素后链表: ";
    traverseList(list);

    destroyList(list);

    return 0;
}
