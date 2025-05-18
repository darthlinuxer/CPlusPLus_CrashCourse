#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class NoobForwardList {
private:
    Node* head;

public:
    NoobForwardList() : head(nullptr) {}

    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    ~NoobForwardList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    NoobForwardList fl;

    // Insert elements
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);
    fl.push_front(0); // Add 0 to the front

    // Print elements
    std::cout << "Forward list elements: ";
    fl.print();

    return 0;
}

/*
Expected Output:
Forward list elements: 0 1 2 3
*/