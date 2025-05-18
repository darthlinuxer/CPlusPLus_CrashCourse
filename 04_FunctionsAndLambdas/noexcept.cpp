// Demonstrates the use of `noexcept` for functions that do not throw exceptions.

#include <iostream>

// The `noexcept` specifier is used to indicate that a function is guaranteed not to throw exceptions.
// This allows the compiler to optimize the code better and provides clarity to the users of the function.
// It is particularly useful in performance-critical code or when working with exception-sensitive operations.
void safeFunction() noexcept {
    // This function is simple and does not perform any operations that could throw exceptions.
    std::cout << "This function is guaranteed not to throw exceptions.\n";
}

int main() {
    // Calling a `noexcept` function ensures that no exceptions will propagate from this call.
    // This can be important in scenarios where exception handling is costly or undesirable.
    safeFunction();

    return 0;
}