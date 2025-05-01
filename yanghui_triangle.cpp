#include <iostream>
#include <iomanip> 
using namespace std;

class LinkQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    LinkQueue() : front(nullptr), rear(nullptr) {}

    ~LinkQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. Cannot dequeue.");
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    void traverse() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

void printPascalTriangle(int n) {
    LinkQueue queue;
    queue.enqueue(1);

    for (int line = 1; line <= n; ++line) {

        cout << string((n - line) * 2, ' ');

        int prev = 0;
        for (int i = 0; i < line; ++i) {
            int curr = queue.dequeue();
            queue.enqueue(prev + curr);
            std::cout << curr << "   ";
            prev = curr;
        }
        queue.enqueue(1); 
        cout << endl;
    }
}

int main() {
    int i = 5;
    cout << "Pascal's Triangle for i = " << i << ":" << endl;
    printPascalTriangle(i);
    return 0;
}
