#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Skip the first 3 elements and take the next 4 (similar to LINQ's Skip and Take)
    for (size_t i = 3; i < 7 && i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}