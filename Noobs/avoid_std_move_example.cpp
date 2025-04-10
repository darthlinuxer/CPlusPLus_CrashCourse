// This file demonstrates the correct way to return local variables in C++.
// Why this is the right way:
// - Modern C++ compilers optimize return values using Return Value Optimization (RVO), making std::move unnecessary.
// - It simplifies the code and avoids potential misuse of std::move.
// How a noob might do it:
// - A noob might use std::move unnecessarily, leading to less readable and potentially error-prone code.

#include <iostream>
#include <vector>

// Demonstrating the correct way to return local variables
std::vector<int> makeVector(int n) {
    std::vector<int> v{1, 2, 3, 4, 5};
    if (n == 0) {
        return v; // No need to use std::move
    }

    std::vector<int> w{6, 7, 8};
    return w; // No need to use std::move
}

int main() {
    auto vec = makeVector(0);
    for (const auto &val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

/* Expected Output:
1 2 3 4 5 
*/