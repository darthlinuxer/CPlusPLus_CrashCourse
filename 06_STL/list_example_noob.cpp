#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class NoobList {
private:
    Node* head;
    Node* tail;

public:
    NoobList() : head(nullptr), tail(nullptr) {}

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    ~NoobList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    NoobList lst;

    // Add elements to the front and back
    lst.push_back(4);  // Add 4 to the back
    lst.push_front(0); // Add 0 to the front
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    // Print all elements
    std::cout << "List elements: ";
    lst.print();

    return 0;
}

/*
Expected Output:
List elements: 0 1 2 3 4
*/