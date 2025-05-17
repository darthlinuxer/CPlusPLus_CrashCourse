#include <iostream>
#include <stack>
#include <vector> // For using std::vector as underlying container
#include <list>   // For using std::list as underlying container

int main() {
    // ====================================================================
    // 1. Basic Stack Operations (Default: std::deque)
    // ====================================================================
    std::cout << "--- 1. Basic Stack Operations (using std::deque by default) ---" << std::endl;
    // std::stack is a container adapter that gives the programmer the functionality of a stack
    // - specifically, a LIFO (last-in, first-out) data structure.
    // By default, it uses std::deque as the underlying container.
    std::stack<int> s;

    // `empty()`: Check if the stack is empty
    std::cout << "Is stack empty initially? " << (s.empty() ? "Yes" : "No") << std::endl;

    // `push(value)`: Adds an element to the top of the stack.
    s.push(10);
    s.push(20);
    // `emplace(args...)`: Constructs an element in-place at the top of the stack (C++11).
    s.emplace(30); // Same as s.push(30) for simple types

    // `size()`: Returns the number of elements in the stack.
    std::cout << "Size of stack: " << s.size() << std::endl;

    // `top()`: Accesses the top element. Does not remove it.
    // Calling top() on an empty stack is undefined behavior.
    if (!s.empty()) {
        std::cout << "Top element is: " << s.top() << std::endl;
    }

    // Process the stack: Access top, then pop.
    std::cout << "Stack elements (LIFO order): ";
    while (!s.empty()) {
        std::cout << s.top() << " "; // Access the top element
        s.pop();                     // `pop()`: Removes the top element.
    }
    std::cout << "\n";
    std::cout << "Is stack empty after processing? " << (s.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Stack with std::vector as Underlying Container
    // ====================================================================
    std::cout << "--- 2. Stack with std::vector ---" << std::endl;
    std::stack<int, std::vector<int>> s_vector; // Second template argument specifies container
    s_vector.push(100);
    s_vector.push(200);
    s_vector.emplace(300);
    std::cout << "Stack (using std::vector) elements: ";
    while(!s_vector.empty()) {
        std::cout << s_vector.top() << " ";
        s_vector.pop();
    }
    std::cout << "\n" << std::endl;

    // Note: std::list can also be used as an underlying container.
    // std::stack<int, std::list<int>> s_list;
    // The underlying container must support: back(), push_back(), pop_back().

    return 0;
}
/*
--- 1. Basic Stack Operations (using std::deque by default) ---
Is stack empty initially? Yes
Size of stack: 3
Top element is: 30
Stack elements (LIFO order): 30 20 10 
Is stack empty after processing? Yes

--- 2. Stack with std::vector ---
Stack (using std::vector) elements: 300 200 100
*/