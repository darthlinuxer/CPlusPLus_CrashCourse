// Exam block #2: Flow control and more data types
// how to control the flow of the program
// floating point types: values, literals, operators
// more integer types: values and literals
// loops and controlling the loop execution
// logic, bitwise and arithmetic operators

#include <iostream>

int main() {
    float f = 3.14f;
    double d = 2.71828;
    short s = 10;
    long l = 100000L;
    // Arithmetic
    double result = f + d;
    // Logic
    bool isPositive = (result > 0);
    // Bitwise
    int a = 5, b = 3;
    int bitwise_and = a & b;
    // Loops
    for (int i = 0; i < 3; ++i) {
        std::cout << "Loop iteration: " << i << std::endl;
    }
    // If-else
    if (isPositive) {
        std::cout << "Result is positive." << std::endl;
    } else {
        std::cout << "Result is not positive." << std::endl;
    }
    std::cout << "Bitwise AND of 5 & 3: " << bitwise_and << std::endl;
    return 0;
}

// Output:
// Loop iteration: 0
// Loop iteration: 1
// Loop iteration: 2
// Result is positive.
// Bitwise AND of 5 & 3: 1
