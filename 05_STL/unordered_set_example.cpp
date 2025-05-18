#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_set
    std::unordered_set<int> uset = {1, 2, 3, 4};

    // Insert an element
    uset.insert(5);

    // Check if an element exists
    if (uset.find(3) != uset.end()) {
        std::cout << "Element 3 found\n";
    }

    // Print all elements
    std::cout << "Unordered set elements: ";
    for (int x : uset) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Element 3 found
Unordered set elements: (order may vary) 1 2 3 4 5
*/