#include <iostream>

class NoobQueue {
private:
    int data[100]; // Fixed-size array for simplicity
    int frontIndex;
    int backIndex;

public:
    NoobQueue() : frontIndex(0), backIndex(0) {}

    void push(int value) {
        data[backIndex++] = value;
    }

    void pop() {
        if (frontIndex < backIndex) {
            ++frontIndex;
        }
    }

    int front() const {
        return data[frontIndex];
    }

    bool empty() const {
        return frontIndex == backIndex;
    }
};

int main() {
    NoobQueue q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Process the queue
    std::cout << "Queue elements: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Queue elements: 10 20 30
*/