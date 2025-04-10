#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Count the number of elements (similar to LINQ's Count)
    std::cout << "Count: " << numbers.size() << "\n";

    return 0;
}