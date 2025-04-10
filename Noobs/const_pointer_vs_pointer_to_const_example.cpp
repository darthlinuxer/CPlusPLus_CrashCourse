// This file explains the difference between const pointers and pointers to const.
// Why this is the right way:
// - It clearly demonstrates the rules and usage of const pointers and pointers to const.
// - It avoids common pitfalls and misunderstandings about const correctness.
// How a noob might do it:
// - A noob might confuse const pointers with pointers to const, leading to unintended behavior.
// - They might not use const at all, resulting in less readable and error-prone code.

#include <iostream>

// Demonstrating the difference between const pointer and pointer to const
void demonstrateConstPointerVsPointerToConst() {
    int x = 10;
    int y = 20;

    // Pointer to const: the value being pointed to cannot be modified
    const int *ptrToConst = &x;
    // *ptrToConst = 15; // Error: cannot modify the value through ptrToConst
    ptrToConst = &y; // Allowed: can change the address it points to

    // Const pointer: the pointer itself cannot change, but the value can be modified
    int *const constPtr = &x;
    *constPtr = 15; // Allowed: can modify the value through constPtr
    // constPtr = &y; // Error: cannot change the address it points to

    // Const pointer to const: neither the pointer nor the value can be modified
    const int *const constPtrToConst = &x;
    // *constPtrToConst = 15; // Error: cannot modify the value
    // constPtrToConst = &y; // Error: cannot change the address it points to

    std::cout << "Pointer to const points to: " << *ptrToConst << std::endl;
    std::cout << "Const pointer points to: " << *constPtr << std::endl;
    std::cout << "Const pointer to const points to: " << *constPtrToConst << std::endl;
}

int main() {
    demonstrateConstPointerVsPointerToConst();
    return 0;
}

/* Expected Output:
Pointer to const points to: 20
Const pointer points to: 15
Const pointer to const points to: 15
*/