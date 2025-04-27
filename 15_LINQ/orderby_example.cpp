#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3};

    // Sort numbers in ascending order (similar to LINQ's OrderBy)
    std::sort(numbers.begin(), numbers.end());

    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}