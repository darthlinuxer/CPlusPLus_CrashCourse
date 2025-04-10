#include <iostream>
#include <vector>

int main() {
    // Using auto to deduce variable types
    auto x = 42; // int
    auto y = 3.14; // double
    auto z = "Hello, World!"; // const char*

    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

    // Using auto in a range-based for loop
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}