#include <iostream>

int main() {
    // Create a fixed-size array
    int arr[3] = {1, 2, 3};

    // Print all elements
    std::cout << "Array elements: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Array elements: 1 2 3
*/