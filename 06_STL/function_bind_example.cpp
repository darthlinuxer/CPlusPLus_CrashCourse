#include <iostream>
#include <functional>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

int main() {
    // Use std::function to store a callable
    std::function<int(int, int)> func = add;

    // Call the function
    std::cout << "Result of add(3, 4): " << func(3, 4) << "\n";

    // Use std::bind to create a partially applied function
    auto addFive = std::bind(add, 5, std::placeholders::_1);

    // Call the partially applied function
    std::cout << "Result of addFive(10): " << addFive(10) << "\n";

    return 0;
}

/*
Expected Output:
Result of add(3, 4): 7
Result of addFive(10): 15
*/