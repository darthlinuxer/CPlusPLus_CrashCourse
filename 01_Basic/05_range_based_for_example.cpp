#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using a range-based for loop to iterate over elements
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Using a range-based for loop with auto
    for (auto num : numbers) {
        std::cout << num * 2 << " ";
    }
    std::cout << std::endl;

    return 0;
}