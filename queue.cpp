#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};


class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        int data = temp->data;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    // clean up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    while (!myQueue.isEmpty()) {
        cout << myQueue.dequeue() << " ";
    }

    return 0;
}
