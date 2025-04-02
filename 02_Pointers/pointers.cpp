#include <iostream>
#include <memory> // For smart pointers

int main() {
    // Basic pointer example
    int value = 42; // Declare an integer variable
    int* ptr = &value; // Pointer stores the address of 'value'

    // Output the value, address, and dereferenced pointer
    std::cout << "Value: " << value << "\n"; // Prints the value of 'value'
    std::cout << "Pointer Address: " << ptr << "\n"; // Prints the address stored in 'ptr'
    std::cout << "Pointer Dereference: " << *ptr << "\n"; // Prints the value at the address stored in 'ptr'

    // Modifying value through pointer
    *ptr = 100; // Dereference the pointer and modify the value it points to
    std::cout << "Modified Value through Pointer: " << value << "\n"; // Prints the updated value of 'value'

    // Null pointer example
    int* nullPtr = nullptr; // A null pointer points to nothing
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is null.\n";
    }

    // Pointer to another pointer (double pointer)
    int** doublePtr = &ptr; // Pointer to a pointer
    std::cout << "Address of ptr: " << doublePtr << "\n"; // Prints the address of 'ptr'
    std::cout << "Value pointed by doublePtr: " << **doublePtr << "\n"; // Dereferences twice to get the value of 'value'

    // Dynamic memory allocation
    int* dynamicPtr = new int(55); // Dynamically allocate memory for an integer and initialize it
    std::cout << "Dynamically Allocated Value: " << *dynamicPtr << "\n"; // Prints the value stored in the dynamically allocated memory
    delete dynamicPtr; // Free the allocated memory
    dynamicPtr = nullptr; // Set the pointer to null after deletion

    // Array and pointer relationship
    int arr[5] = {1, 2, 3, 4, 5}; // Declare an array
    int* arrPtr = arr; // Pointer to the first element of the array
    std::cout << "Array Elements via Pointer:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << *(arrPtr + i) << " "; // Access array elements using pointer arithmetic
    }
    std::cout << "\n";

    // Constant pointer (pointer itself cannot change)
    int anotherValue = 10;
    int* const constPtr = &value; // constPtr must always point to 'value'
    *constPtr = 200; // Allowed: modifying the value pointed to
    std::cout << "Modified Value via constPtr: " << value << "\n";
    // constPtr = &anotherValue; // Not allowed: changing the pointer itself

    // Pointer to constant (value cannot be modified through the pointer)
    const int* ptrToConst = &anotherValue; // Pointer to a constant value
    std::cout << "Value via ptrToConst: " << *ptrToConst << "\n";
    // *ptrToConst = 20; // Not allowed: modifying the value through the pointer

    // Constant pointer to constant
    const int* const constPtrToConst = &anotherValue;
    std::cout << "Value via constPtrToConst: " << *constPtrToConst << "\n";
    // *constPtrToConst = 30; // Not allowed: modifying the value
    // constPtrToConst = &value; // Not allowed: changing the pointer

    // Complex pointer operations
    // Pointer to a dynamically allocated array
    int* dynamicArray = new int[5]{10, 20, 30, 40, 50};
    std::cout << "Dynamically Allocated Array Elements:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << dynamicArray[i] << " "; // Access elements using array indexing
    }
    std::cout << "\n";
    delete[] dynamicArray; // Free the dynamically allocated array

    // Using smart pointers (unique_ptr)
    std::unique_ptr<int> smartPtr(new int(77)); // Unique pointer managing a dynamically allocated integer
    std::cout << "Value via smartPtr: " << *smartPtr << "\n";

    // Pointer to a function
    auto add = [](int a, int b) -> int { return a + b; }; // Lambda function
    int (*funcPtr)(int, int) = add; // Pointer to the lambda function
    std::cout << "Result of add(5, 10) via funcPtr: " << funcPtr(5, 10) << "\n";

    // Pointer to a struct
    struct Point {
        int x, y;
    };
    Point point = {3, 4};
    Point* pointPtr = &point;
    std::cout << "Point coordinates via pointer: (" << pointPtr->x << ", " << pointPtr->y << ")\n";

    return 0;
}