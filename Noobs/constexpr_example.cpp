// This file demonstrates the use of constexpr for compile-time computations in C++.
// Why this is the right way:
// - It allows computations to be performed at compile time, improving runtime performance.
// - It ensures that values are constant and cannot be modified at runtime.
// How a noob might do it:
// - A noob might perform such computations at runtime, leading to unnecessary overhead.

#include <iostream>

// Demonstrating the use of constexpr for compile-time computations
constexpr int sumOf1ToN(int n) {
    return n * (n + 1) / 2;
}

int main() {
    constexpr int limit = 1000;
    constexpr int triangleNumber = sumOf1ToN(limit);

    std::cout << "Sum of numbers from 1 to " << limit << " is: " << triangleNumber << std::endl;
    return 0;
}

/* Expected Output:
Sum of numbers from 1 to 1000 is: 500500
*/