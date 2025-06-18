// Exam block #3: Functions
// functions, declaring and invoking functions, side effects
// different methods of passing parameters and their purpose
// default parameters, inline functions, overloaded functions

#include <iostream>

void printMessage() {
    std::cout << "Hello from a function!" << std::endl;
}

int add(int a, int b = 5) { // default parameter
    return a + b;
}

inline int multiply(int a, int b) {
    return a * b;
}

void increment(int& ref) { // pass by reference
    ref++;
}

void show(int x) {
    std::cout << "Show int: " << x << std::endl;
}
void show(double x) { // overloaded function
    std::cout << "Show double: " << x << std::endl;
}

int main() {
    printMessage();
    std::cout << "Add: " << add(3) << std::endl;
    std::cout << "Multiply: " << multiply(2, 4) << std::endl;
    int val = 10;
    increment(val);
    std::cout << "Incremented: " << val << std::endl;
    show(7);
    show(3.14);
    return 0;
}

// Output:
// Hello from a function!
// Add: 8
// Multiply: 8
// Incremented: 11
// Show int: 7
// Show double: 3.14
