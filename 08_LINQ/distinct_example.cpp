#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 3, 3, 4};
    std::set<int> distinctNumbers(numbers.begin(), numbers.end());

    // Remove duplicates (similar to LINQ's Distinct)
    for (int n : distinctNumbers) {
        std::cout << n << " ";
    }

    return 0;
}