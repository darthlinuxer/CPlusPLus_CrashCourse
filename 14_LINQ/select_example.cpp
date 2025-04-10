#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Transform numbers by squaring them (similar to LINQ's Select)
    for (int n : numbers | std::views::transform([](int x) { return x * x; })) {
        std::cout << n << " ";
    }

    return 0;
}