#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Find the minimum value (similar to LINQ's Min)
    int minValue = *std::min_element(numbers.begin(), numbers.end());

    std::cout << "Min: " << minValue << "\n";

    return 0;
}