#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Push elements
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Process the priority queue
    std::cout << "Priority queue elements: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}