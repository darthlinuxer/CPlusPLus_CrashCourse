#include <iostream>

// Function to find an element in an array and return a pointer to it
int* findElement(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return &arr[i]; // Return pointer to the found element
        }
    }
    return nullptr; // Return null pointer if the element is not found
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int valueToFind = 30;
    int* result = findElement(numbers, size, valueToFind);

    if (result != nullptr) {
        std::cout << "Value " << valueToFind << " found at address: " << result << "\n";
        std::cout << "Value at that address: " << *result << "\n";
    } else {
        std::cout << "Value " << valueToFind << " not found in the array.\n";
    }

    // Example with a value not in the array
    valueToFind = 60;
    result = findElement(numbers, size, valueToFind);

    if (result != nullptr) {
        std::cout << "Value " << valueToFind << " found at address: " << result << "\n";
        std::cout << "Value at that address: " << *result << "\n";
    } else {
        std::cout << "Value " << valueToFind << " not found in the array.\n";
    }

    return 0;
}

/*
Value 30 found at address: 00DDFF18
Value at that address: 30
Value 60 not found in the array.
*/