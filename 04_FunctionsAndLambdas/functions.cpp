#include <iostream>
#include <string>
#include <functional> // For std::function

// 1. Basic function: Adds two integers
int add(int a, int b) {
    return a + b; // Returns the sum of a and b
}

// 2. Function with default arguments
int multiply(int a, int b = 2) {
    return a * b; // Multiplies a by b (default is 2)
}

// 3. Function overloading: Same name, different parameters
double add(double a, double b) {
    return a + b; // Returns the sum of two doubles
}

// 4. Inline function: Suggests to the compiler to expand the function at the call site
/*
Inline Functions
An inline function is a suggestion to the compiler to replace the function call with the actual function code at the call site. This can reduce the overhead of a function call, especially for small, frequently used functions. However, the compiler is not obligated to inline the function—it is merely a request.
Benefits of Inline Functions:
Performance Improvement: Eliminates the overhead of a function call (e.g., pushing arguments onto the stack, jumping to the function, and returning).
Code Optimization: Allows the compiler to perform additional optimizations, such as constant folding or loop unrolling.
Readability: Keeps the code modular while avoiding the performance cost of function calls.
When to Use:
Use inline functions for small, simple functions (e.g., getters, setters, or mathematical operations like subtract in your code).
Avoid inlining large functions, as it can increase the size of the binary (code bloat) and negatively impact performance.
*/
inline int subtract(int a, int b) {
    return a - b; // Returns the difference of a and b
}

// 5. Function with pass-by-reference
void increment(int& value) {
    value++; // Increments the value by 1
}

// 6. Function with const reference to avoid copying
/*
Const Functions
A const function ensures that the function does not modify the object or parameter it is operating on. This is particularly useful for maintaining immutability and avoiding unintended side effects.
Benefits of Const Functions:
Safety: Prevents accidental modification of data.
Optimization: Allows the compiler to make assumptions about the immutability of the data, potentially leading to better optimizations.
Readability: Signals to other developers that the function does not alter the input or the state of the object.
*/
void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!\n"; // Greets the user
}

// 7. Lambda function: Anonymous function
auto divide = [](double a, double b) -> double {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!"); // Handle division by zero
    }
    return a / b; // Returns the result of division
};

// 8. Function pointer: Points to a function
int (*operation)(int, int) = add; // Points to the add function

// 9. std::function: More flexible function wrapper
std::function<int(int, int)> customOperation = subtract; // Wraps the subtract function

int main() {
    // Demonstrating basic function
    std::cout << "Sum (int): " << add(3, 4) << "\n";

    // Demonstrating function with default arguments
    std::cout << "Product with default argument: " << multiply(5) << "\n";
    std::cout << "Product without default argument: " << multiply(5, 3) << "\n";

    // Demonstrating function overloading
    std::cout << "Sum (double): " << add(3.5, 4.2) << "\n";

    // Demonstrating inline function
    std::cout << "Difference: " << subtract(10, 4) << "\n";

    // Demonstrating pass-by-reference
    int value = 10;
    increment(value);
    std::cout << "Incremented value: " << value << "\n";

    // Demonstrating const reference
    greet("Alice");

    // Demonstrating lambda function
    try {
        std::cout << "Division: " << divide(10.0, 2.0) << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    // Demonstrating function pointer
    std::cout << "Using function pointer (add): " << operation(7, 3) << "\n";

    // Demonstrating std::function
    std::cout << "Using std::function (subtract): " << customOperation(10, 5) << "\n";

    return 0; // Indicate successful execution
}

/*
Sum (int): 7
Product with default argument: 10
Product without default argument: 15
Sum (double): 7.7
Difference: 6
Incremented value: 11
Hello, Alice!
Division: 5
Using function pointer (add): 10
Using std::function (subtract): 5
*/