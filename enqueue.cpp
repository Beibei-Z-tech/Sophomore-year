#include <iostream>
#include <vector>
using namespace std;
class CircularQueue {
private:
    vector<char> buffer;
    int head;
    int tail;
    int size;
    int capacity;

public:
    CircularQueue(int cap = 10) : buffer(cap), head(0), tail(0), size(0), capacity(cap) {}

    bool enqueue(char item) {
        if (isFull()) {
            return false;
        }
        buffer[tail] = item;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue(char &item) {
        if (isEmpty()) {
            return false;
        }
        item = buffer[head];
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    char front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return buffer[head];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void traverse() const {
        int index = head;
        for (int i = 0; i < size; ++i) {
            cout << buffer[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }

    ~CircularQueue() {
        // Destructor: the vector will be automatically cleared here.
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');
    queue.enqueue('d');

    cout << "Front element: " << queue.front() << endl;

    cout << "Queue elements: ";
    queue.traverse();

    char item;
    while (!queue.isEmpty()) {
        queue.dequeue(item);
        cout << "Dequeued: " << item << endl;
    }

    for (char c = 'a'; !queue.isFull(); ++c) {
        queue.enqueue(c);
    }

    cout << "Queue elements: ";
    queue.traverse();

    cout << "Queue is full" << endl;

    return 0;
}
