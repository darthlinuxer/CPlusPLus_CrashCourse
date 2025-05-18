#include <iostream>
#include <array>

int main() {
    // Create a fixed-size array
    std::array<int, 3> arr = {1, 2, 3};

    // Print all elements
    std::cout << "Array elements: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Array elements: 1 2 3
*/