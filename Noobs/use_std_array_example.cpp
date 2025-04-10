// This file demonstrates the use of std::array instead of C-style arrays in C++.
// Why this is the right way:
// - std::array provides bounds checking and better type safety compared to C-style arrays.
// - It integrates seamlessly with STL algorithms and modern C++ features.
// How a noob might do it:
// - A noob might use raw C-style arrays, leading to potential bugs and less maintainable code.

#include <iostream>
#include <array>

// Demonstrating the use of std::array instead of C-style arrays
template<std::size_t size>
void betterFunction(std::array<int, size> &arr) {
    for (const auto &val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// How a noob might do it:
// A noob might use raw C-style arrays, which lack bounds checking and type safety.
// Example:
void noobFunction(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void usingCArrayNoob() {
    const int n = 5;
    int arr[n] = {1, 2, 3, 4, 5}; // Using a raw C-style array
    noobFunction(arr, n);
}

void usingCArray() {
    const int n = 5;
    std::array<int, n> arr = {1, 2, 3, 4, 5}; // Using std::array
    betterFunction(arr);
}

int main() {
    usingCArray();
    usingCArrayNoob();
    return 0;
}

/* Expected Output:
1 2 3 4 5 
1 2 3 4 5 
*/