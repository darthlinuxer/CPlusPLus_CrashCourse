// This file demonstrates the lack of guaranteed evaluation order for function arguments in C++.
// Why this is the right way:
// - It highlights the importance of avoiding code that depends on a specific evaluation order.
// - It encourages writing clear and predictable code.
// How a noob might do it:
// - A noob might assume a specific evaluation order, leading to undefined behavior.

#include <iostream>
#include <string>

// Demonstrating that evaluation order of function arguments is not guaranteed
void printValues(int a, int b, int c) {
    std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
    int i = 0;
    auto increment = [&i]() -> int {
        return ++i;
    };

    // The order of evaluation of arguments is not guaranteed
    printValues(increment(), increment(), increment());

    return 0;
}

/* Expected Output:
All permutations of 1 2 3 are possible, e.g.,
1 2 3
1 3 2
2 1 3
... */