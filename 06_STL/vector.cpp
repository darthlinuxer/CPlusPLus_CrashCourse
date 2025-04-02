#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 3, 8, 1, 2};

    // Sort the vector
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Find an element
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    if (it != numbers.end()) {
        std::cout << "Found number: " << *it << "\n";
    } else {
        std::cout << "Number not found.\n";
    }

    return 0;
}