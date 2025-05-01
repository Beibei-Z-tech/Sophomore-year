#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

ListNode* CreateList(int n, int arr[], int index) {
    if (n <= 0 || index < 0) return nullptr; 
    ListNode* head = new ListNode(arr[index]);
    head->next = CreateList(n - 1, arr, index - 1); 
    return head;
}

void PrintList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int FindMax(ListNode* head) {
    if (head == nullptr) return INT_MIN; 
    int maxInRest = FindMax(head->next); 
    return max(head->data, maxInRest); 
}

void DestroyList(ListNode* head) {
    if (head == nullptr) return;
    DestroyList(head->next); 
    delete head;
}

int main() {
    int n = 6; 
    int arr[6] = {20, 100, 5, 214, 88, 99}; 

    ListNode* head = CreateList(n, arr, n - 1);

    cout << "链表为: ";
    PrintList(head);

    int maxVal = FindMax(head);
    cout << "最大值是: " << maxVal << endl;

    DestroyList(head);

    return 0;
}
