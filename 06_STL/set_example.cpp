#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::set<int> uniqueNumbers = {5, 3, 8, 3, 1};

    // Insert elements
    std::pair<std::set<int>::iterator, bool> result = uniqueNumbers.insert(2);
    if (result.second) {
        std::cout << "Element " << *result.first << " inserted\n";
    } else {
        std::cout << "Element 2 already exists\n";
    }

    result = uniqueNumbers.insert(8); // Duplicate, won't be added
    if (result.second) {
        std::cout << "Element " << *result.first << " inserted\n";
    } else {
        std::cout << "Element " << *result.first << " already exists\n";
    }

    // Iterate over the set
    std::cout << "Unique numbers: ";
    for (int const& num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Erase if even
    // The erase-remove idiom with std::remove_if is not suitable for std::set.
    // Instead, iterate and erase matching elements:
    for (auto it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ) {
        if (*it % 2 == 0) { // If num is even
            it = uniqueNumbers.erase(it); // Erase element and update iterator to the next one
        } else {
            ++it; // Move to the next element
        }
    }
    

    std::cout << "Unique numbers after erasing even numbers: ";
    for (int const& num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}

/* Output
Element 2 inserted
Element 8 already exists
Unique numbers: 1 2 3 5 8 
Unique numbers after erasing even numbers: 1 3 5 
*/