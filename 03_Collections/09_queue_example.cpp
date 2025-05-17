#include <iostream>
#include <queue>
#include <list> // For using std::list as underlying container
#include <string>

int main() {
    // ====================================================================
    // 1. Basic Queue Operations (Default: std::deque)
    // ====================================================================
    std::cout << "--- 1. Basic Queue Operations (using std::deque by default) ---" << std::endl;
    // std::queue is a container adapter that gives the programmer the functionality of a queue
    // - specifically, a FIFO (first-in, first-out) data structure.
    // By default, it uses std::deque as the underlying container.
    std::queue<int> q;

    // `empty()`: Check if the queue is empty.
    std::cout << "Is queue empty initially? " << (q.empty() ? "Yes" : "No") << std::endl;

    // `push(value)`: Adds an element to the end of the queue (the "back").
    q.push(10);
    q.push(20);
    // `emplace(args...)`: Constructs an element in-place at the end of the queue (C++11).
    q.emplace(30); // Same as q.push(30) for simple types

    // `size()`: Returns the number of elements in the queue.
    std::cout << "Size of queue: " << q.size() << std::endl;

    // `front()`: Accesses the next element in the queue (the "front"). Does not remove it.
    // `back()`: Accesses the last element in the queue (the "back"). Does not remove it.
    // Calling front() or back() on an empty queue is undefined behavior.
    if (!q.empty()) {
        std::cout << "Front element is: " << q.front() << std::endl;
        std::cout << "Back element is: " << q.back() << std::endl;
    }

    // Process the queue: Access front, then pop.
    std::cout << "Queue elements (FIFO order): ";
    while (!q.empty()) {
        std::cout << q.front() << " "; // Access the front element
        q.pop();                      // `pop()`: Removes the front element.
    }
    std::cout << "\n";
    std::cout << "Is queue empty after processing? " << (q.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Queue with std::list as Underlying Container
    // ====================================================================
    std::cout << "--- 2. Queue with std::list ---" << std::endl;
    // std::list can also be used as the underlying container.
    std::queue<std::string, std::list<std::string>> q_list;
    q_list.push("Alpha");
    q_list.push("Bravo");
    q_list.emplace("Charlie");

    std::cout << "Queue (using std::list) elements: ";
    while(!q_list.empty()) {
        std::cout << q_list.front() << " ";
        q_list.pop();
    }
    std::cout << "\n" << std::endl;

    // The underlying container must support: empty(), size(), front(), back(), push_back(), pop_front().

    return 0;
}
/*
--- 1. Basic Queue Operations (using std::deque by default) ---
Is queue empty initially? Yes
Size of queue: 3
Front element is: 10
Back element is: 30
Queue elements (FIFO order): 10 20 30 
Is queue empty after processing? Yes

--- 2. Queue with std::list ---
Queue (using std::list) elements: Alpha Bravo Charlie
*/