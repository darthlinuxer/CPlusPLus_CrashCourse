#include <iostream>

void modifyByReference(int& ref) {
    ref *= 2;
}

void modifyByPointer(int* ptr) {
    if (ptr) {
        *ptr += 10;
    }
}

int main() {
    int value = 5;

    // Passing by reference
    std::cout << "Original value: " << value << std::endl;
    modifyByReference(value);
    std::cout << "After modifyByReference: " << value << std::endl;

    // Passing by pointer
    modifyByPointer(&value);
    std::cout << "After modifyByPointer: " << value << std::endl;

    return 0;
}