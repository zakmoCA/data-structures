#include <iostream>

class Node {
public:
    int data; // types must b known at compile time
    Node* next; 

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        // if list empty
        if (head == nullptr) {
            head = newNode; // newNode is first in list
            return;
        }

        // if list not empty
        Node* temp = head; // start at head
        while (temp->next != nullptr) {
            temp = temp->next; // node by node traversal
        }
        temp->next = newNode; // last node pointer to point to newNode
        // newNode is now last node in list
    }

    void display() {
        Node* temp = head; // temp = i
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.display(); // 1 -> 2 -> 3 -> NULL

    return 0;
}
