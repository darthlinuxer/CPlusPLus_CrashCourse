// This file demonstrates the importance of addressing compiler warnings in C++.
// Why this is the right way:
// - It ensures that potential issues are caught early, improving code quality and reliability.
// - It encourages writing clean, warning-free code.
// How a noob might do it:
// - A noob might ignore compiler warnings, leading to bugs and undefined behavior.

#include <iostream>

// Demonstrating the importance of addressing compiler warnings
void demonstrateCompilerWarnings() {
    int x; // Uninitialized variable (may cause a warning)
    // std::cout << x << std::endl; // Uncommenting this line would use an uninitialized variable

    int y = 10;
    if (y = 5) { // Assignment instead of comparison (may cause a warning)
        std::cout << "y is 5" << std::endl;
    }

    // Corrected code:
    if (y == 5) {
        std::cout << "y is 5" << std::endl;
    }
}

int main() {
    demonstrateCompilerWarnings();
    return 0;
}

/* Expected Output:
No output, as the corrected code ensures proper behavior without warnings.
*/