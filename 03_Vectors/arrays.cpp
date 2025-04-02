#include <iostream>
#include <iterator> // For std::size
#include <array>    // For std::array

int main() {
    // 1. Basic array initialization
    int numbers[] = {1, 2, 3, 4, 5};
    const int size = std::size(numbers); // Get the size of the array

    // 2. Accessing array elements
    std::cout << "Accessing array elements using index:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }

    // 3. Range-based for loop
    std::cout << "\nArray elements using range-based for loop:\n";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 4. Modifying array elements
    std::cout << "\nModifying array elements:\n";
    for (int i = 0; i < size; ++i) {
        numbers[i] *= 2; // Double each element
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }

    // 5. Multidimensional arrays
    std::cout << "\nDemonstrating a 2D array:\n";
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << "matrix[" << row << "][" << col << "] = " << matrix[row][col] << " ";
        }
        std::cout << "\n";
    }

    // 6. Array of characters (C-style strings)
    std::cout << "\nC-style string (character array):\n";
    char greeting[] = "Hello, World!";
    std::cout << greeting << "\n";

    // 7. Array size and bounds
    std::cout << "\nArray size and bounds:\n";
    std::cout << "Size of numbers array: " << size << "\n";
    std::cout << "Accessing out-of-bounds (undefined behavior):\n";
    // Uncommenting the next line may cause a crash or undefined behavior
    // std::cout << numbers[size] << "\n";

    // 8. Using std::array (safer alternative to C-style arrays)
    std::cout << "\nUsing std::array (from <array>):\n";
    std::array<int, 5> stdNumbers = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < stdNumbers.size(); ++i) {
        std::cout << "stdNumbers[" << i << "] = " << stdNumbers[i] << "\n";
    }

    return 0;
}