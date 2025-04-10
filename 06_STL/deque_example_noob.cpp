#include <iostream>

class NoobDeque {
private:
    int data[100]; // Fixed-size array for simplicity
    int frontIndex;
    int backIndex;

public:
    NoobDeque() : frontIndex(50), backIndex(50) {} // Start in the middle

    void push_back(int value) {
        data[backIndex++] = value;
    }

    void push_front(int value) {
        data[--frontIndex] = value;
    }

    void pop_back() {
        if (backIndex > frontIndex) {
            --backIndex;
        }
    }

    void pop_front() {
        if (frontIndex < backIndex) {
            ++frontIndex;
        }
    }

    void print() const {
        for (int i = frontIndex; i < backIndex; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    NoobDeque dq;

    // Insert elements at both ends
    dq.push_back(10);  // Add 10 to the back
    dq.push_front(20); // Add 20 to the front
    dq.push_back(30);  // Add 30 to the back

    // Access elements
    std::cout << "Deque elements: ";
    dq.print();

    // Remove elements from both ends
    dq.pop_front(); // Remove the front element (20)
    dq.pop_back();  // Remove the back element (30)

    std::cout << "Deque after popping: ";
    dq.print();

    return 0;
}

/*
Expected Output:
Deque elements: 20 10 30
Deque after popping: 10
*/