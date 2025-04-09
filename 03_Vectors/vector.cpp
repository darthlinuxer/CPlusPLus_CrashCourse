#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::reverse

int main() {
    // 1. Create a vector with an initializer list.
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 2. Add elements to the vector using `push_back`.
    numbers.push_back(6); // Adds 6 to the end of the vector.

    // 3. Display the vector using a range-based for loop.
    std::cout << "Numbers in the vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 4. Access elements safely using `.at()` (throws an exception if out of bounds).
    std::cout << "The first number is: " << numbers.at(0) << "\n";

    // 5. Access elements using the subscript operator (no bounds checking).
    std::cout << "The second number is: " << numbers[1] << "\n";

    // 6. Resize the vector to a larger size, filling new elements with a default value.
    numbers.resize(10, 0); // Resize to 10 elements, filling new elements with 0.
    std::cout << "Vector after resizing to 10 elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 7. Shrink the vector back to a smaller size.
    numbers.resize(5); // Truncate the vector to 5 elements.
    std::cout << "Vector after resizing back to 5 elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 8. Insert elements at a specific position.
    numbers.insert(numbers.begin() + 2, 99); // Insert 99 at index 2.
    std::cout << "Vector after inserting 99 at index 2: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 9. Erase an element at a specific position.
    numbers.erase(numbers.begin() + 2); // Remove the element at index 2.
    std::cout << "Vector after erasing the element at index 2: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 10. Sort the vector in ascending order.
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Vector after sorting in ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 11. Reverse the vector.
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Vector after reversing: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 12. Clear all elements from the vector.
    numbers.clear();
    std::cout << "Vector after clearing all elements. Size: " << numbers.size() << "\n";

    // 13. Check if the vector is empty.
    if (numbers.empty()) {
        std::cout << "The vector is now empty.\n";
    }

    // 14. Reserve capacity to avoid frequent reallocations.
    numbers.reserve(20); // Reserve space for 20 elements.
    std::cout << "Reserved capacity for 20 elements. Current capacity: " << numbers.capacity() << "\n";

    // 15. Add elements again to demonstrate reserved capacity.
    for (int i = 1; i <= 10; ++i) {
        numbers.push_back(i);
    }
    std::cout << "Vector after adding 10 elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 16. Demonstrate the use of iterators.
    std::cout << "Vector elements using iterators: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 17. Demonstrate the use of `const_iterator` for read-only access.
    std::cout << "Vector elements using const_iterator: ";
    for (std::vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 18. Demonstrate the use of `std::vector` with custom types (e.g., pairs).
    std::vector<std::pair<int, std::string>> pairs = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::cout << "Vector of pairs: ";
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << "\n";

    return 0;
}

/*
Numbers in the vector: 1 2 3 4 5 6 
The first number is: 1
The second number is: 2
Vector after resizing to 10 elements: 1 2 3 4 5 6 0 0 0 0
Vector after resizing back to 5 elements: 1 2 3 4 5
Vector after inserting 99 at index 2: 1 2 99 3 4 5
Vector after erasing the element at index 2: 1 2 3 4 5
Vector after sorting in ascending order: 1 2 3 4 5
Vector after reversing: 5 4 3 2 1
Vector after clearing all elements. Size: 0
The vector is now empty.
Reserved capacity for 20 elements. Current capacity: 20
Vector after adding 10 elements: 1 2 3 4 5 6 7 8 9 10
Vector elements using iterators: 1 2 3 4 5 6 7 8 9 10
Vector elements using const_iterator: 1 2 3 4 5 6 7 8 9 10
Vector of pairs: (1, one) (2, two) (3, three)
*/