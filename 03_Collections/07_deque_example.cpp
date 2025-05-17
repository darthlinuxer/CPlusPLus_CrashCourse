#include <iostream>
#include <deque>
#include <algorithm> // For std::sort (though deque sort is not as common as vector sort)
#include <iterator>  // For std::ostream_iterator

int main() {
    // ====================================================================
    // 1. Initialization and Basic Properties
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Properties ---" << std::endl;
    // Method 1: Default constructor
    std::deque<int> dq;
    std::cout << "Initially, dq.empty(): " << (dq.empty() ? "true" : "false") << ", dq.size(): " << dq.size() << std::endl;

    // Method 2: Initializer list (C++11)
    std::deque<int> dq_init = {1, 2, 3, 4, 5};
    std::cout << "dq_init: ";
    for(int n : dq_init) std::cout << n << " ";
    std::cout << std::endl << std::endl;

    // ====================================================================
    // 2. Adding Elements (Front, Back, Middle)
    // ====================================================================
    std::cout << "--- 2. Adding Elements ---" << std::endl;
    // `push_back()`: Add to the back
    dq.push_back(10);  // Add 10 to the back
    // `push_front()`: Add to the front
    dq.push_front(20); // Add 20 to the front
    dq.push_back(30);  // Add 30 to the back
    dq.emplace_front(5); // Construct 5 at the front
    dq.emplace_back(35); // Construct 35 at the back
    std::cout << "Deque after push/emplace front/back: ";
    for (int num : dq) std::cout << num << " ";
    std::cout << "\n";

    // `insert()`: Insert elements at a specific position
    auto it_insert = dq.begin() + 2; // Iterator to the 3rd element
    dq.insert(it_insert, 99); // Insert 99 before the element at it_insert
    std::cout << "Deque after inserting 99 at index 2: ";
    for (int num : dq) std::cout << num << " ";
    std::cout << "\n" << std::endl;

    // ====================================================================
    // 3. Accessing Elements
    // ====================================================================
    std::cout << "--- 3. Accessing Elements ---" << std::endl;
    // `operator[]`: Access element by index (no bounds checking)
    std::cout << "Element at index 0 (dq[0]): " << dq[0] << std::endl;
    // `at()`: Access element by index (with bounds checking)
    std::cout << "Element at index 1 (dq.at(1)): " << dq.at(1) << std::endl;
    try {
        std::cout << dq.at(100) << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Caught exception for at(100): " << oor.what() << std::endl;
    }
    // `front()`: Access the first element
    std::cout << "Front element (dq.front()): " << dq.front() << std::endl;
    // `back()`: Access the last element
    std::cout << "Back element (dq.back()): " << dq.back() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 4. Removing Elements
    // ====================================================================
    std::cout << "--- 4. Removing Elements ---" << std::endl;
    std::cout << "Current deque before pops: "; for(int n : dq) std::cout << n << " "; std::cout << "\n";
    // `pop_front()`: Remove the front element
    dq.pop_front(); // Remove the front element (20)
    // `pop_back()`: Remove the back element
    dq.pop_back();  // Remove the back element (30)
    std::cout << "Deque after pop_front and pop_back: ";
    for (int num : dq) std::cout << num << " ";
    std::cout << "\n";

    // `erase()`: Remove element(s) at a specific position or range
    if (dq.size() >= 2) {
        auto it_erase = dq.begin() + 1; // Iterator to the 2nd element
        dq.erase(it_erase);
        std::cout << "Deque after erasing element at index 1: ";
        for (int num : dq) std::cout << num << " ";
        std::cout << "\n";
    }

    // `clear()`: Removes all elements
    dq_init.clear();
    std::cout << "dq_init after clear(): size = " << dq_init.size() << ", empty = " << (dq_init.empty() ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 5. Size, Capacity, and Iterators
    // ====================================================================
    std::cout << "--- 5. Size, Capacity, and Iterators ---" << std::endl;
    std::cout << "Current dq size: " << dq.size() << std::endl;
    // Deque doesn't have `capacity()` like vector, but has `shrink_to_fit()`
    dq.shrink_to_fit(); // Request to reduce memory usage

    // Iterating through deque
    std::cout << "Iterating dq using iterators: ";
    for(auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Deques can be sorted, though it's less common than with vectors due to memory layout.
    std::sort(dq.begin(), dq.end());
    std::cout << "dq after sorting: ";
    std::copy(dq.begin(), dq.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    return 0;
}

/*
--- 1. Initialization and Basic Properties ---
Initially, dq.empty(): true, dq.size(): 0
dq_init: 1 2 3 4 5 

--- 2. Adding Elements ---
Deque after push/emplace front/back: 5 20 10 30 35 
Deque after inserting 99 at index 2: 5 20 99 10 30 35 

--- 3. Accessing Elements ---
Element at index 0 (dq[0]): 5
Element at index 1 (dq.at(1)): 20
Front element (dq.front()): 5
Back element (dq.back()): 35

--- 4. Removing Elements ---
Current deque before pops: 5 20 99 10 30 35 
Deque after pop_front and pop_back: 20 99 10 30 
Deque after erasing element at index 1: 20 10 30 
dq_init after clear(): size = 0, empty = true

--- 5. Size, Capacity, and Iterators ---
Current dq size: 3
Iterating dq using iterators: 20 10 30 
dq after sorting: 10 20 30
Caught exception for at(100): deque::_M_range_check: __n (which is 100)>= this->size() (which is 6)
*/