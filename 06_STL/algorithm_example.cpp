#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Transform: Multiply each element by 2
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });
    std::cout << "After transform: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    // Accumulate: Calculate the sum of all elements
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << "\n";

    // Find: Search for the element 6
    auto it = std::find(vec.begin(), vec.end(), 6);
    if (it != vec.end()) {
        std::cout << "Found: " << *it << "\n";
    } else {
        std::cout << "Not found\n";
    }

    return 0;
}

/*
Expected Output:
After transform: 2 4 6 8 10
Sum: 30
Found: 6
*/