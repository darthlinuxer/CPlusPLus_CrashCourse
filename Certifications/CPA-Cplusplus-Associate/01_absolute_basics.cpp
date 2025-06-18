// Exam block #1: Absolute basics
// machine and high-level programming languages, compilation process
// obtaining the machine code: compilation process
// writing simple programs
// variables
// integers: values, literals, operators
// characters: values, literals, operators
// dealing with streams and basic input/output operations

#include <iostream>

int main() {
    // Variable declaration
    int integerVar = 42;
    char charVar = 'A';
    // Integer operations
    int sum = integerVar + 10;
    // Character operations
    char nextChar = charVar + 1;
    // Output
    std::cout << "Integer: " << integerVar << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Char: " << charVar << ", Next Char: " << nextChar << std::endl;
    // Input
    int inputVar;
    std::cout << "Enter a number: ";
    // std::cin >> inputVar;
    inputVar = 100; // For testing purposes, we set a default value
    std::cout << "You entered: " << inputVar << std::endl;
    return 0;
}

// Output:
// Integer: 42
// Sum: 52
// Char: A, Next Char: B
// Enter a number: You entered: 100
