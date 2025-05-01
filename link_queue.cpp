#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    LinkQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~LinkQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot dequeue.");
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int frontElement() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. No front element.");
        }
        return front->data;
    }

    void traverse() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Front element: " << queue.frontElement() << endl;

    cout << "Queue elements: ";
    queue.traverse();

    while (!queue.isEmpty()) {
        cout << "Dequeued: " << queue.dequeue() << endl;
    }

    for (int i = 1; i <= 10; ++i) {
        queue.enqueue(i);
    }

    cout << "Queue elements: ";
    queue.traverse();

    return 0;
}
