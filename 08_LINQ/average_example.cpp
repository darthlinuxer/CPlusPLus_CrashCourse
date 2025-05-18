#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Average of all numbers (similar to LINQ's Average)
    double average = static_cast<double>(std::accumulate(numbers.begin(), numbers.end(), 0)) / numbers.size();

    std::cout << "Average: " << average << "\n";

    return 0;
}