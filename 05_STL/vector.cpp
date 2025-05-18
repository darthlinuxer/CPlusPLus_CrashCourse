#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> numbers = {1, 2 , 3, 4, 5, 6, 7, 8, 9}; // Initialize a vector with some numbers
    //vector size and vector capacity
    std::cout << "Size of vector: " << numbers.size() << "\n"; // Number of elements
    std::cout << "Capacity of vector: " << numbers.capacity() << "\n"; // Number of elements that can be stored without reallocation
    // Adding elements
    numbers.push_back(10); // Add 10 to the end
    std::cout << "Size after push_back: " << numbers.size() << "\n"; // Size after adding an element
    std::cout << "Capacity after push_back: " << numbers.capacity() << "\n"; // Capacity after adding an element  
    // reserve capacity
    numbers.reserve(20); // Reserve space for 20 elements
    std::cout << "Capacity after reserve: " << numbers.capacity() << "\n"; // Capacity after reserving space

    std::cout << "First number: " << numbers[0] << "\n"; // Accessing the first element
    std::cout << "Number at position 10 : " << numbers[10] << "\n"; // Accessing the 11th element (out of bounds, will cause undefined behavior)
    try {
        std::cout << numbers.at(10) << "\n"; // Accessing the first element (safe access)
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << "\n";
    }

    // Sort the vector
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // sort with lambda descending
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    // Find an element by valye
    auto it = std::find(begin(numbers), numbers.end(), 3);
    if (it != numbers.end()) {
        std::cout << "\nFound number: " << *it << "\n";
    } else {
        std::cout << "Number not found.\n";
    }

    //Find-if example: find elements by condition   
    auto it2 = std::find_if(numbers.begin(), numbers.end(), [](int n) { return n > 5; });
    if (it2 != numbers.end()) {
        std::cout << "Found number greater than 5: " << *it2 << "\n";
    } else {
        std::cout << "No number greater than 5 found.\n";
    }

    //create a lambda to filter even numbers
    std::function<bool(int)> is_even = [](int n) { return n % 2 == 0; };
    //create a lambda to filter odd numbers
    auto is_odd = [](int n) { return n % 2 == 1; };
    
    // remove if value is even
    std::vector<int>::iterator removed = std::remove_if(numbers.begin(), numbers.end(), is_even);
    // remove_if does not actually remove the elements from the vector, it just moves them to the end
    // and returns an iterator to the new end of the vector.
    std::cout << "Numbers after remove_if: ";
    for (auto number: numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";
    numbers.erase(removed, numbers.end());
    // numbers.erase actually removes the elements from the vector.
    std::cout << "After removing even numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}

/* Expected Output:
ize of vector: 9
Capacity of vector: 9
Size after push_back: 10
Capacity after push_back: 18
Capacity after reserve: 20
First number: 1
Number at position 10 : 0
Sorted numbers: 1 2 3 4 5 6 7 8 9 10 
Sorted numbers: 10 9 8 7 6 5 4 3 2 1 
Found number: 3
Found number greater than 5: 10
Numbers after remove_if: 9 7 5 3 1 5 4 3 2 1 
After removing even numbers: 9 7 5 3 1 
Out of range error: vector::_M_range_check: __n (which is 10) >= this->size() (which is 10)
*/