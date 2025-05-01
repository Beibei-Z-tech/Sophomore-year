#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* initList() {
    return nullptr;
}

void traverseList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int getListLength(ListNode* head) {
    int length = 0;
    ListNode* p = head;
    while (p != nullptr) {
        length++;
        p = p->next;
    }
    return length;
}

int getElement(ListNode* head, int index) {
    ListNode* p = head;
    int pos = 1;
    while (p != nullptr && pos < index) {
        p = p->next;
        pos++;
    }
    if (p != nullptr && pos == index) {
        return p->data;
    } else {
        return -1;
    }
}

void headInsert(ListNode*& head, int value) {
    ListNode* newNode = new ListNode;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void tailInsert(ListNode*& head, int value) {
    ListNode* newNode = new ListNode;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
    }
}

bool insertNode(ListNode*& head, int index, int value) {
    if (index < 1) return false;
    if (index == 1) {
        headInsert(head, value);
        return true;
    }
    ListNode* newNode = new ListNode;
    newNode->data = value;
    ListNode* p = head;
    int pos = 1;
    while (p != nullptr && pos < index - 1) {
        p = p->next;
        pos++;
    }
    if (p == nullptr) return false;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

bool deleteNode(ListNode*& head, int index, int& value) {
    if (head == nullptr || index < 1) return false;
    if (index == 1) {
        ListNode* delNode = head;
        head = head->next;
        value = delNode->data;
        delete delNode;
        return true;
    }
    ListNode* p = head;
    int pos = 1;
    while (p->next != nullptr && pos < index - 1) {
        p = p->next;
        pos++;
    }
    if (p->next == nullptr || pos < index - 1) return false;
    ListNode* delNode = p->next;
    p->next = delNode->next;
    value = delNode->data;
    delete delNode;
    return true;
}

void clearList(ListNode*& head) {
    ListNode* p = head;
    while (p != nullptr) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }
    head = nullptr;
}

void destroyList(ListNode*& head) {
    clearList(head);
}

int findElement(ListNode* head, int e) {
    ListNode* p = head;
    int pos = 1;
    while (p != nullptr) {
        if (p->data == e) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

int main() {
    ListNode* LA = initList();

    traverseList(LA);

    int value = getElement(LA, 2);
    if (value != -1) {
        cout << "第2号节点的值是: " << value << endl;
    } else {
        cout << "没有2号节点" << endl;
    }

    ListNode* LB = initList();

    traverseList(LB);

    value = getElement(LB, 1);
    if (value != -1) {
        cout << "第1号节点的值是: " << value << endl;
    } else {
        cout << "没有1号节点" << endl;
    }

    value = getElement(LB, 5);
    if (value != -1) {
        cout << "第5号节点的值是: " << value << endl;
    } else {
        cout << "没有5号节点" << endl;
    }

    value = getElement(LB, 6);
    if (value != -1) {
        cout << "第6号节点的值是: " << value << endl;
    } else {
        cout << "没有6号节点" << endl;
    }

    ListNode* LC = initList();
    for (int i = 1; i <= 5; ++i) {
        tailInsert(LC, i);
    }

    traverseList(LC);

    value = getElement(LC, 0);
    if (value != -1) {
        cout << "第0号节点的值是: " << value << endl;
    } else {
        cout << "没有0号节点" << endl;
    }

    value = getElement(LC, 5);
    if (value != -1) {
        cout << "第5号节点的值是: " << value << endl;
    } else {
        cout << "没有5号节点" << endl;
    }

    value = getElement(LC, 6);
    if (value != -1) {
        cout << "第6号节点的值是: " << value << endl;
    } else {
        cout << "没有6号节点" << endl;
    }

    clearList(LB);

    traverseList(LB);

    destroyList(LA);
    destroyList(LB);
    destroyList(LC);

    ListNode* list = initList();

    for (int i = 1; i <= 5; ++i) {
        insertNode(list, i, i);
    }

    if (!insertNode(list, 6, 6)) {
        cout << "无法插入" << endl;
    }
    if (!insertNode(list, 3, 33)) {
        cout << "无法插入" << endl;
    }

    traverseList(list);

    int elements[] = {5, 6, 3, 12};
    for (int e:elements) {
        int pos = findElement(list, e);
        if (pos != -1) {
            cout << "元素 " << e << " 的序号是: " << pos << endl;
        } else {
            cout << "没有该元素 " << e << endl;
        }
    }

    int delPos[] = {1, 5, 3, 20};
    for (int pos:delPos) {
        int data;
        if (deleteNode(list, pos, data)) {
            cout << "删除了序号 " << pos << " 的节点，其数据为: " << data << endl;
        } else {
            cout << "无法删除序号 " << pos << " 位置的元素" << endl;
        }
    }

    // 7
}