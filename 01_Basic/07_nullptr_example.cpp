#include <iostream>

void checkPointer(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Pointer is null." << std::endl;
    } else {
        std::cout << "Pointer value: " << *ptr << std::endl;
    }
}

int main() {
    int* validPtr = new int(10);
    int* nullPtr = nullptr;

    checkPointer(validPtr);
    checkPointer(nullPtr);

    delete validPtr;
    return 0;
}