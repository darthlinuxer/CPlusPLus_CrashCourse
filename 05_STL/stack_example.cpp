#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Process the stack
    std::cout << "Stack elements: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";

    return 0;
}