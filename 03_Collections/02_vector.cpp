#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::reverse

int main() {
    // ====================================================================
    // 1. Initialization and Basic Properties
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Properties ---" << std::endl;
    // Method 1: Initializer list (C++11)
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Initialized vector: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // Method 2: Default constructor (empty vector)
    std::vector<std::string> names;
    std::cout << "names vector is empty: " << (names.empty() ? "true" : "false") << ", size: " << names.size() << std::endl;

    // Method 3: Constructor with size and initial value
    std::vector<double> values(5, 3.14); // 5 doubles, each initialized to 3.14
    std::cout << "values vector (size 5, val 3.14): ";
    for (double val : values) std::cout << val << " ";
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 2. Adding Elements
    // ====================================================================
    std::cout << "--- 2. Adding Elements ---" << std::endl;
    // `push_back()`: Adds an element to the end.
    numbers.push_back(6); // Adds 6 to the end of the vector.
    std::cout << "After push_back(6): ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // `emplace_back()`: Constructs an element in-place at the end (more efficient for complex objects).
    numbers.emplace_back(7); // Constructs 7 at the end.
    std::cout << "After emplace_back(7): ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // `insert()`: Inserts elements at a specific position.
    numbers.insert(numbers.begin() + 2, 99); // Insert 99 at index 2.
    std::cout << "After inserting 99 at index 2: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 3. Accessing Elements
    // ====================================================================
    std::cout << "--- 3. Accessing Elements ---" << std::endl;
    // `at()`: Access element with bounds checking (throws std::out_of_range if out of bounds).
    std::cout << "Element at index 0 (using at()): " << numbers.at(0) << "\n";
    try {
        std::cout << numbers.at(100) << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Caught exception for at(100): " << oor.what() << std::endl;
    }

    // Subscript operator `[]`: Access element without bounds checking (undefined behavior if out of bounds).
    std::cout << "Element at index 1 (using []): " << numbers[1] << "\n";

    // `front()`: Access the first element.
    std::cout << "First element (using front()): " << numbers.front() << "\n";

    // `back()`: Access the last element.
    std::cout << "Last element (using back()): " << numbers.back() << "\n";

    // `data()`: Returns a direct pointer to the underlying array.
    int* pData = numbers.data();
    std::cout << "First element via data pointer: " << pData[0] << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 4. Modifying and Resizing
    // ====================================================================
    std::cout << "--- 4. Modifying and Resizing ---" << std::endl;
    // `resize()`: Changes the number of elements.
    numbers.resize(10, 0); // Resize to 10 elements, filling new elements with 0.
    std::cout << "Vector after resizing to 10 elements: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    numbers.resize(5); // Truncate the vector to 5 elements.
    std::cout << "Vector after resizing back to 5 elements: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // `erase()`: Removes elements from the vector.
    // Erase the element at index 2 (which is the third element, currently 99 if we re-insert)
    // Let's re-initialize for clarity for erase:
    numbers = {10, 20, 30, 40, 50};
    std::cout << "Vector before erase: "; for(int n : numbers) std::cout << n << " "; std::cout << "\n";
    numbers.erase(numbers.begin() + 2); // Remove the element '30' at index 2.
    std::cout << "Vector after erasing element at index 2: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // Erase a range of elements
    numbers.erase(numbers.begin(), numbers.begin() + 2); // Erase first two elements
    std::cout << "Vector after erasing first two elements: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 5. Capacity Management
    // ====================================================================
    std::cout << "--- 5. Capacity Management ---" << std::endl;
    std::vector<int> cap_vec;
    std::cout << "Initial capacity: " << cap_vec.capacity() << ", size: " << cap_vec.size() << std::endl;
    // `reserve()`: Request a change in capacity.
    cap_vec.reserve(20); // Reserve space for 20 elements.
    std::cout << "After reserve(20): capacity: " << cap_vec.capacity() << ", size: " << cap_vec.size() << std::endl;

    for (int i = 1; i <= 10; ++i) cap_vec.push_back(i);
    std::cout << "After adding 10 elements: capacity: " << cap_vec.capacity() << ", size: " << cap_vec.size() << std::endl;
    std::cout << "Vector content: "; for(int n : cap_vec) std::cout << n << " "; std::cout << "\n";

    // `shrink_to_fit()`: Reduces capacity to fit the size (C++11).
    cap_vec.shrink_to_fit();
    std::cout << "After shrink_to_fit(): capacity: " << cap_vec.capacity() << ", size: " << cap_vec.size() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 6. Iterators and Algorithms
    // ====================================================================
    std::cout << "--- 6. Iterators and Algorithms ---" << std::endl;
    numbers = {5, 1, 4, 2, 3}; // Re-initialize for sorting/reversing
    std::cout << "Original numbers for algorithms: "; for(int n : numbers) std::cout << n << " "; std::cout << "\n";

    // `begin()`, `end()`: Iterators for traversing.
    std::cout << "Vector elements using iterators: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // `cbegin()`, `cend()`: Const iterators for read-only access.
    std::cout << "Vector elements using const_iterator: ";
    for (std::vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // `rbegin()`, `rend()`: Reverse iterators.
    std::cout << "Vector elements using reverse_iterator: ";
    for (std::vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " "; // Iterates 3 2 4 1 5
    }
    std::cout << "\n";

    // `crbegin()`, `crend()`: Const reverse iterators.
    std::cout << "Vector elements using const_reverse_iterator: ";
    for (std::vector<int>::const_reverse_iterator crit = numbers.crbegin(); crit != numbers.crend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << "\n";

    // `std::sort` (from <algorithm>)
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Vector after sorting in ascending order: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // `std::reverse` (from <algorithm>)
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Vector after reversing: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 7. Clearing and Checking Emptiness
    // ====================================================================
    std::cout << "--- 7. Clearing and Checking Emptiness ---" << std::endl;
    // `clear()`: Removes all elements from the vector. Size becomes 0. Capacity may not change.
    numbers.clear();
    std::cout << "Vector after clearing all elements. Size: " << numbers.size() << "\n";

    // `empty()`: Checks if the vector is empty.
    if (numbers.empty()) {
        std::cout << "The vector is now empty.\n";
    }
    std::cout << std::endl;

    // ====================================================================
    // 8. Vector of Custom Types
    // ====================================================================
    std::cout << "--- 8. Vector of Custom Types ---" << std::endl;
    std::vector<std::pair<int, std::string>> pairs = {{1, "one"}, {2, "two"}, {3, "three"}};
    pairs.emplace_back(4, "four"); // Using emplace_back for pairs
    std::cout << "Vector of pairs: ";
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << "\n";

    return 0;
}

/*
--- 1. Initialization and Basic Properties ---
Initialized vector: 1 2 3 4 5 
names vector is empty: true, size: 0
values vector (size 5, val 3.14): 3.14 3.14 3.14 3.14 3.14 

--- 2. Adding Elements ---
After push_back(6): 1 2 3 4 5 6 
After emplace_back(7): 1 2 3 4 5 6 7 
After inserting 99 at index 2: 1 2 99 3 4 5 6 7 

--- 3. Accessing Elements ---
Element at index 0 (using at()): 1
Caught exception for at(100): vector::_M_range_check: __n (which is 100) >= this->size() (which is 8)
Element at index 1 (using []): 2
First element (using front()): 1
Last element (using back()): 7
First element via data pointer: 1

--- 4. Modifying and Resizing ---
Vector after resizing to 10 elements: 1 2 99 3 4 5 6 7 0 0 
Vector after resizing back to 5 elements: 1 2 99 3 4 
Vector before erase: 10 20 30 40 50 
Vector after erasing element at index 2: 10 20 40 50 
Vector after erasing first two elements: 40 50 

--- 5. Capacity Management ---
Initial capacity: 0, size: 0
After reserve(20): capacity: 20, size: 0
After adding 10 elements: capacity: 20, size: 10
Vector content: 1 2 3 4 5 6 7 8 9 10 
After shrink_to_fit(): capacity: 10, size: 10

--- 6. Iterators and Algorithms ---
Original numbers for algorithms: 5 1 4 2 3 
Vector elements using iterators: 5 1 4 2 3 
Vector elements using const_iterator: 5 1 4 2 3 
Vector elements using reverse_iterator: 3 2 4 1 5 
Vector elements using const_reverse_iterator: 3 2 4 1 5 
Vector after sorting in ascending order: 1 2 3 4 5 
Vector after reversing: 5 4 3 2 1 

--- 7. Clearing and Checking Emptiness ---
Vector after clearing all elements. Size: 0
The vector is now empty.

--- 8. Vector of Custom Types ---
Vector of pairs: (1, one) (2, two) (3, three) (4, four)
*/