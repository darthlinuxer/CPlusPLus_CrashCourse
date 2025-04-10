#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // First element (similar to LINQ's First)
    if (!numbers.empty()) {
        std::cout << "First: " << numbers.front() << "\n";
    }

    return 0;
}