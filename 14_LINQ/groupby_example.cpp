#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 3, 3, 4};
    std::map<int, int> groups;

    // Group numbers by their value (similar to LINQ's GroupBy)
    for (int n : numbers) {
        groups[n]++;
    }

    for (const auto& [key, count] : groups) {
        std::cout << "Value: " << key << ", Count: " << count << "\n";
    }

    return 0;
}