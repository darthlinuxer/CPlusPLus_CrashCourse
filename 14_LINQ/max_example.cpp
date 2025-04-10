#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Find the maximum value (similar to LINQ's Max)
    int maxValue = *std::max_element(numbers.begin(), numbers.end());

    std::cout << "Max: " << maxValue << "\n";

    return 0;
}