#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

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