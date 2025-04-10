#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Check if all numbers are positive (similar to LINQ's All)
    bool allPositive = std::all_of(numbers.begin(), numbers.end(), [](int x) { return x > 0; });

    std::cout << "All positive: " << (allPositive ? "true" : "false") << "\n";

    return 0;
}