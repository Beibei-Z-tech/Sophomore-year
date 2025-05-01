#include <iostream>
#include <list>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};
Node* createCircularList(int n) {
    Node* head = nullptr;
    Node* prev = nullptr;

    for (int i = 1; i <= n; ++i) {
        Node* newNode = new Node(i);
        if (!head) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = head;
    return head;
}
Node* deleteNode(Node* target, Node*& head) {
    Node* prev = head;
    while (prev->next != target) {
        prev = prev->next;
    }
    prev->next = target->next;
    if (target == head) {
        head = head->next;
    }
    delete target;
    return prev->next;
}
void josephus(int n, int m) {
    Node* head = createCircularList(n);
    Node* current = head;
    cout << "自杀顺序: ";
    while (n > 1) {
        for (int count = 1; count < m; ++count) {
            current = current->next;
        }
        cout << current->data << " ";
        current = deleteNode(current, head);
        --n;
    }
    cout << endl;
    cout << "约瑟夫的位置: " << head->data << endl;
}

int main() {
    int n = 10; 
    int m = 3;  
    josephus(n, m);
    return 0;
}
