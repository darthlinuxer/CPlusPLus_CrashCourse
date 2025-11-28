#include <iostream>

// ============================================================================
// Use `constexpr` for values that can be evaluated at compile time.
// `constexpr` functions must have a body that can be evaluated at compile time.
// This means they can only use constructs that the compiler can understand and evaluate
// without actually running the program.
constexpr int square(int x) {
    // This function calculates the square of an integer.
    // Because it's `constexpr`, if 'x' is known at compile time,
    // the result will be computed during compilation.
    return x * x;
}

// Example of a constexpr function with branching.
// Even though this function uses recursion and a conditional (ternary operator),
// it's still `constexpr` because the compiler can determine the result at compile time
// for any constant input 'n'.
constexpr int factorial(int n) {
    // This function calculates the factorial of a non-negative integer.
    // It uses a ternary operator for branching:
    // (condition) ? (value if true) : (value if false)
    return (n <= 1) ? 1 : (n * factorial(n - 1));
    // Base case: if n is 0 or 1, return 1.
    // Recursive case: otherwise, return n * factorial(n - 1).
}

int main() {
    // `constexpr int value = 5;` declares a compile-time constant named 'value'.
    // Its value (5) is known at compile time and cannot be changed during the program's execution.
    constexpr int value = 5;

    // `constexpr int result = square(value);` calls the `square` function with 'value'.
    // Because 'square' is `constexpr` and 'value' is a compile-time constant,
    // the compiler will compute the result (25) at compile time.
    // The result is then stored directly in the executable.
    constexpr int result = square(value); // Computed at compile time.

    // `constexpr int fact = factorial(4);` calls the `factorial` function with 4.
    // Again, since 'factorial' is `constexpr` and 4 is a literal,
    // the compiler will calculate the factorial (24) during compilation.
    constexpr int fact = factorial(4);   // Computed at compile time.

    // Output the results to the console.
    // The values of 'value', 'result', and 'fact' are already known at compile time,
    // so the output is predetermined.
    std::cout << "The square of " << value << " is " << result << ".\n";
    std::cout << "The factorial of 4 is " << fact << ".\n";

    return 0;
}

// ============================================================================
// Advantages of `constexpr`
// ============================================================================
// 1. Performance:
//    - Calculations are performed at compile time, not runtime.
//    - This eliminates the overhead of performing those calculations during program execution.
//    - The result is directly embedded in the executable, making it faster.
// 2. Safety:
//    - The compiler checks `constexpr` expressions and functions at compile time.
//    - If there's an error (e.g., using a non-constant value where a constant is required),
//      the compiler will catch it, preventing runtime errors.
// 3. Code Clarity:
//    - `constexpr` clearly indicates which values and functions are intended to be
//      evaluated at compile time.
//    - This makes the code easier to understand and reason about.
// 4. Template Metaprogramming:
//    - `constexpr` is essential for template metaprogramming, where compile-time
//      computation is a core concept.
// 5. Optimization:
//    - The compiler can perform more aggressive optimizations when it knows that
//      certain values are constant.

// ============================================================================
// When to Use `constexpr`
// ============================================================================
// 1. Compile-Time Constants:
//    - When you need a value that is known at compile time and will not change.
//      Examples: array sizes, mathematical constants, configuration values.
// 2. Compile-Time Functions:
//    - When you have a function that can be evaluated at compile time, given
//      constant inputs.
//    - This is especially useful for calculations that are needed to define
//      other compile-time constants.
// 3. Template Arguments:
//    - When you need to use a value as a template argument (e.g., array size).
//      Template arguments must be compile-time constants.
// 4. Performance-Critical Code:
//    - When you have calculations that are performance-sensitive and can be
//      done at compile time.
// 5. Static Assertions:
//    - `constexpr` can be used in conjunction with `static_assert` to perform
//      compile-time checks.


/* output
The square of 5 is 25.
The factorial of 4 is 24.
*/