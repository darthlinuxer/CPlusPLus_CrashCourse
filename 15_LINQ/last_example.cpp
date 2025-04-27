#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Last element (similar to LINQ's Last)
    if (!numbers.empty()) {
        std::cout << "Last: " << numbers.back() << "\n";
    }

    return 0;
}