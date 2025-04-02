#include <iostream>

// Use `constexpr` for values that can be evaluated at compile time.
constexpr int square(int x) {
    return x * x;
}

// Example of a constexpr function with branching.
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int value = 5;
    constexpr int result = square(value); // Computed at compile time.
    constexpr int fact = factorial(4);   // Computed at compile time.

    std::cout << "The square of " << value << " is " << result << ".\n";
    std::cout << "The factorial of 4 is " << fact << ".\n";

    return 0;
}