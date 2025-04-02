#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers = {5, 3, 8, 3, 1};

    // Insert elements
    uniqueNumbers.insert(2);
    uniqueNumbers.insert(8); // Duplicate, won't be added

    // Iterate over the set
    std::cout << "Unique numbers: ";
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}