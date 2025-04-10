// This file demonstrates the concept of string literal lifetimes in C++.
// Why this is the right way:
// - It highlights that string literals have a static lifetime and are safe to use throughout the program.
// - It shows how to safely modify copies of string literals.
// How a noob might do it:
// - A noob might attempt to modify a string literal directly, leading to undefined behavior.

#include <iostream>
#include <string>

// Demonstrating string literal lifetimes
const char *stringLiteralLifetimes() {
    char hello[] = "hello!"; // Makes a copy of the string literal
    std::cout << hello << '\n';
    hello[0] = 'H'; // Modifies the copy
    std::cout << hello << '\n';

    return "string literals"; // String literals live for the entire program lifetime
}

int main() {
    const char *result = stringLiteralLifetimes();
    std::cout << result << std::endl;
    return 0;
}

/* Expected Output:
hello!
Hello!
string literals
*/