#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Check if any number is greater than 3 (similar to LINQ's Any)
    bool anyGreaterThanThree = std::any_of(numbers.begin(), numbers.end(), [](int x) { return x > 3; });

    std::cout << "Any greater than 3: " << (anyGreaterThanThree ? "true" : "false") << "\n";

    return 0;
}