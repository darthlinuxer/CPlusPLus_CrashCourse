#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Insert elements at both ends
    dq.push_back(10);  // Add 10 to the back
    dq.push_front(20); // Add 20 to the front
    dq.push_back(30);  // Add 30 to the back

    // Access elements
    std::cout << "Deque elements: ";
    for (int num : dq) {
        std::cout << num << " "; // Print all elements
    }
    std::cout << "\n";

    // Remove elements from both ends
    dq.pop_front(); // Remove the front element (20)
    dq.pop_back();  // Remove the back element (30)

    std::cout << "Deque after popping: ";
    for (int num : dq) {
        std::cout << num << " "; // Print remaining elements
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Deque elements: 20 10 30
Deque after popping: 10
*/