#include <iostream>
#include <tuple>

int main() {
    // Create a tuple with an int, a string, and a double
    std::tuple<int, std::string, double> myTuple(1, "Hello", 3.14);

    // Access and print tuple elements
    std::cout << "Tuple elements: "
              << std::get<0>(myTuple) << ", " // Access the first element
              << std::get<1>(myTuple) << ", " // Access the second element
              << std::get<2>(myTuple) << "\n"; // Access the third element

    return 0;
}

/*
Expected Output:
Tuple elements: 1, Hello, 3.14
*/