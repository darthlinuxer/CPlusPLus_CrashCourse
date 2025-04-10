// This file demonstrates the use of structs to return multiple values from a function.
// Why this is the right way:
// - It provides a clear and structured way to return multiple values.
// - It avoids the need for out parameters or global variables.
// How a noob might do it:
// - A noob might use out parameters, making the code less readable and harder to maintain.

#include <iostream>

// Demonstrating the use of a struct to return multiple values
struct Values {
    int x, y;
};

Values getValues(int n) {
    return {n, n + 1};
}

int main() {
    auto [x, y] = getValues(5);
    std::cout << "x: " << x << ", y: " << y << std::endl;
    return 0;
}

/* Expected Output:
x: 5, y: 6
*/