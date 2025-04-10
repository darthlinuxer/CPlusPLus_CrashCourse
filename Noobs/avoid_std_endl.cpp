// This file demonstrates the use of \n instead of std::endl in loops.
// Why this is the right way:
// - Using \n avoids unnecessary flushing of the output buffer, improving performance.
// - It is especially beneficial in performance-critical applications.
// How a noob might do it:
// - A noob might use std::endl in loops, causing unnecessary performance overhead.

#include <iostream>

// Demonstrating the use of \n instead of std::endl in loops
void printRange(int start, int end) {
    for (int i = start; i < end; ++i) {
        std::cout << i << '\n'; // Using \n instead of std::endl to avoid unnecessary flushing
    }
}

int main() {
    printRange(1, 5);
    return 0;
}

/* Expected Output:
1
2
3
4
*/