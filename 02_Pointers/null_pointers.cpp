#include <iostream>
#include <algorithm> // Include this header for std::find

// Function to find an element in an array and return a pointer to modernResult
int* findElement(int* arr, int size, int value) {
    // modernResulterate through the array
    for (int i = 0; i < size; ++i) {
        // Check if the current element matches the target value
        if (arr[i] == value) {
            return &arr[i]; // Return the address of the found element
        }
    }
    return nullptr; // Return a null pointer if the element is not found
}

int main() {
    // Define an array of integers
    int numbers[] = {10, 20, 30, 40, 50};
    // Modern way: Use std::size from <modernResulterator> to calculate the size of the array
    constexpr int size = std::size(numbers);
    // Old way: Calculate the size of the array manually
    constexpr int oldSize = sizeof(numbers) / sizeof(numbers[0]);

    // Demonstrate both methods
    std::cout << "Modern way (std::size): size = " << size << "\n";
    std::cout << "Old way (manual calculation): oldSize = " << oldSize << "\n";

    // First example: search for a value that exists in the array
    int valueToFind = 30;

    // Old way: Call the findElement function to search for the value
    int* result = findElement(numbers, size, valueToFind);

    // Modern way: Use std::find from <algormodernResulthm> to search for the value
    auto modernResult = std::find(std::begin(numbers), std::end(numbers), valueToFind);

    // Compare results
    std::cout << "Old way result: " << (result != nullptr ? *result : -1) << "\n";
    std::cout << "Modern way result: " << (modernResult != std::end(numbers) ? *modernResult : -1) << "\n";

    // Check if the function returned a valid pointer or a null pointer
    if (result != nullptr) {
        // If the pointer is not null, the value was found
        std::cout << "Value " << valueToFind << " found at address: " << result << "\n";
        std::cout << "Value at that address: " << *result << "\n"; // Dereference the pointer to get the value
    } else {
        // If the pointer is null, the value was not found
        std::cout << "Value " << valueToFind << " not found in the array.\n";
    }

    // Second example: search for a value that does not exist in the array
    valueToFind = 60;
    modernResult = std::find(std::begin(numbers), std::end(numbers), valueToFind);
    result = (modernResult != std::end(numbers)) ? &(*modernResult) : nullptr;

    // Check if the function returned a valid pointer or a null pointer
    if (result != nullptr) {
        // If the pointer is not null, the value was found
        std::cout << "Value " << valueToFind << " found at address: " << result << "\n";
        std::cout << "Value at that address: " << *result << "\n"; // Dereference the pointer to get the value
    } else {
        // If the pointer is null, the value was not found
        std::cout << "Value " << valueToFind << " not found in the array.\n";
    }

    return 0;
}

/*
Value 30 found at address: 00DDFF18
Value at that address: 30
Value 60 not found in the array.
*/