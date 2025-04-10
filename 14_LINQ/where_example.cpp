#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // Filter numbers that are even (similar to LINQ's Where)
    for (int n : numbers | std::views::filter([](int x) { return x % 2 == 0; })) {
        std::cout << n << " ";
    }

    return 0;
}