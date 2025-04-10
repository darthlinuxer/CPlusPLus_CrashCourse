// This file demonstrates the use of std::move as a cast to an rvalue reference in C++.
// Why this is the right way:
// - It explicitly indicates that an object can be moved, improving code clarity.
// - It avoids unnecessary copies, optimizing performance.
// How a noob might do it:
// - A noob might not use std::move, leading to unnecessary copies and reduced performance.

#include <iostream>
#include <string>
#include <utility>

// Demonstrating that std::move is a cast to an rvalue reference
void demonstrateMove() {
    std::string str = "Hello, World!";
    std::string movedStr = std::move(str); // str is now in a valid but unspecified state

    std::cout << "Moved string: " << movedStr << std::endl;
    std::cout << "Original string after move: " << str << std::endl; // str is empty or unspecified
}

int main() {
    demonstrateMove();
    return 0;
}

/* Expected Output:
Moved string: Hello, World!
Original string after move: 
*/