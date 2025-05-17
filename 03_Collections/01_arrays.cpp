#include <iostream>
#include <iterator> // For std::size
#include <array>    // For std::array
#include <numeric>  // For std::iota (C++11)
#include <algorithm> // For std::for_each

// Function to print a C-style array (demonstrates decay to pointer)
void print_c_array(const int* arr, int size) {
    std::cout << "Printing C-style array (passed as pointer): ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Function to print a std::array (passed by const reference)
template<size_t N>
void print_std_array(const std::array<int, N>& arr) {
    std::cout << "Printing std::array (passed by const reference): ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // ====================================================================
    // 1. C-style arrays
    // ====================================================================
    std::cout << "--- 1. C-style arrays ---" << std::endl;
    // Basic initialization
    int numbers[] = {1, 2, 3, 4, 5};
    const int c_array_size = std::size(numbers); // Get the size of the array (C++17)
                                             // For older C++, use sizeof(numbers) / sizeof(numbers[0])

    // Accessing elements using index
    std::cout << "Accessing C-style array elements using index:\n";
    for (int i = 0; i < c_array_size; ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }

    // Range-based for loop (C++11)
    std::cout << "\nC-style array elements using range-based for loop:\n";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Modifying elements
    std::cout << "\nModifying C-style array elements:\n";
    for (int i = 0; i < c_array_size; ++i) {
        numbers[i] *= 2; // Double each element
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }

    // Multidimensional arrays
    std::cout << "\nDemonstrating a 2D C-style array:\n";
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << "matrix[" << row << "][" << col << "] = " << matrix[row][col] << " ";
        }
        std::cout << "\n";
    }

    // Array of characters (C-style strings)
    std::cout << "\nC-style string (character array):\n";
    char greeting[] = "Hello, World!"; // Null-terminated
    std::cout << greeting << "\n";
    std::cout << "Size of greeting (including null terminator): " << std::size(greeting) << "\n";

    // Array size and bounds
    std::cout << "\nC-style array size and bounds:\n";
    std::cout << "Size of numbers array: " << c_array_size << "\n";
    std::cout << "Accessing out-of-bounds (undefined behavior):\n";
    // numbers[c_array_size]; // This is out of bounds!

    // Array decay: When a C-style array is passed to a function, it often decays to a pointer
    // to its first element. The size information is lost.
    std::cout << "\nArray decay example:\n";
    print_c_array(numbers, c_array_size); // 'numbers' decays to 'int*'
    std::cout << "sizeof(numbers) in main: " << sizeof(numbers) << std::endl;
    // Inside print_c_array, sizeof(arr) would be sizeof(int*).
    std::cout << std::endl;

    // ====================================================================
    // 2. std::array (from <array> header, C++11)
    // ====================================================================
    std::cout << "--- 2. std::array ---" << std::endl;
    // Safer alternative to C-style arrays. Size is part of the type.
    std::array<int, 5> stdNumbers = {10, 20, 30, 40, 50};

    // Accessing elements
    std::cout << "std::array elements using index:\n";
    for (size_t i = 0; i < stdNumbers.size(); ++i) {
        std::cout << "stdNumbers[" << i << "] = " << stdNumbers[i] << "\n";
    }

    // Accessing elements with at() (provides bounds checking)
    std::cout << "stdNumbers.at(1): " << stdNumbers.at(1) << std::endl;
    try {
        std::cout << stdNumbers.at(5) << std::endl; // This will throw std::out_of_range
    } catch (const std::out_of_range& oor) {
        std::cerr << "Caught exception: " << oor.what() << std::endl;
    }

    // Range-based for loop
    std::cout << "\nstd::array elements using range-based for loop:\n";
    for (int num : stdNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Modifying elements
    std::cout << "\nModifying std::array elements:\n";
    for (size_t i = 0; i < stdNumbers.size(); ++i) {
        stdNumbers[i] /= 10;
        std::cout << "stdNumbers[" << i << "] = " << stdNumbers[i] << "\n";
    }

    // Size, empty, fill
    std::cout << "stdNumbers size: " << stdNumbers.size() << std::endl;
    std::cout << "stdNumbers is empty? " << (stdNumbers.empty() ? "Yes" : "No") << std::endl;
    stdNumbers.fill(7); // Fill the array with 7
    std::cout << "stdNumbers after fill(7): ";
    for (int num : stdNumbers) std::cout << num << " ";
    std::cout << "\n";

    // Front and back elements
    std::array<char, 4> letters = {'a', 'b', 'c', 'd'};
    std::cout << "First letter: " << letters.front() << ", Last letter: " << letters.back() << std::endl;

    // Data pointer (access to underlying C-style array)
    char* data_ptr = letters.data(); // Get pointer to underlying char array
    std::cout << "Data pointer points to: " << *data_ptr << std::endl;

    // Passing std::array to functions
    std::cout << "\nPassing std::array to functions:\n";
    print_std_array(stdNumbers); // Passed by const reference

    // std::to_array (C++20) - creates a std::array from a C-style array or initializer list
    #if __cplusplus >= 202002L
    std::cout << "\nUsing std::to_array (C++20):\n";
    auto arr_from_c = std::to_array(numbers); // Deduces type and size
    std::cout << "std::array from C-style array: ";
    for(int x : arr_from_c) std::cout << x << " ";
    std::cout << "\n";

    auto arr_from_init_list = std::to_array({100, 200, 300});
    std::cout << "std::array from initializer list: ";
    for(int x : arr_from_init_list) std::cout << x << " ";
    std::cout << "\n";
    #else
    std::cout << "\nstd::to_array examples require C++20.\n";
    #endif

    // Using algorithms with std::array
    std::array<int, 5> another_std_array;
    std::iota(another_std_array.begin(), another_std_array.end(), 100); // Fill with 100, 101, ...
    std::cout << "another_std_array filled with iota: ";
    std::for_each(another_std_array.cbegin(), another_std_array.cend(), [](int x){ std::cout << x << " "; });
    std::cout << "\n";

    return 0;
}

/*
--- 1. C-style arrays ---
Accessing C-style array elements using index:
numbers[0] = 1
numbers[1] = 2
numbers[2] = 3
numbers[3] = 4
numbers[4] = 5

C-style array elements using range-based for loop:
1 2 3 4 5 

Modifying C-style array elements:
numbers[0] = 2
numbers[1] = 4
numbers[2] = 6
numbers[3] = 8
numbers[4] = 10

Demonstrating a 2D C-style array:
matrix[0][0] = 1 matrix[0][1] = 2 matrix[0][2] = 3 
matrix[1][0] = 4 matrix[1][1] = 5 matrix[1][2] = 6 

C-style string (character array):
Hello, World!
Size of greeting (including null terminator): 14

C-style array size and bounds:
Size of numbers array: 5
Accessing out-of-bounds (undefined behavior):

Array decay example:
Printing C-style array (passed as pointer): 2 4 6 8 10 
sizeof(numbers) in main: 20

--- 2. std::array ---
std::array elements using index:
stdNumbers[0] = 10
stdNumbers[1] = 20
stdNumbers[2] = 30
stdNumbers[3] = 40
stdNumbers[4] = 50
stdNumbers.at(1): 20
Caught exception: array::at: __n (which is 5) >= _Nm (which is 5)

std::array elements using range-based for loop:
10 20 30 40 50 

Modifying std::array elements:
stdNumbers[0] = 1
stdNumbers[1] = 2
stdNumbers[2] = 3
stdNumbers[3] = 4
stdNumbers[4] = 5
stdNumbers size: 5
stdNumbers is empty? No
stdNumbers after fill(7): 7 7 7 7 7 
First letter: a, Last letter: d
Data pointer points to: a

Passing std::array to functions:
Printing std::array (passed by const reference): 7 7 7 7 7 

std::to_array examples require C++20.
another_std_array filled with iota: 100 101 102 103 104
*/