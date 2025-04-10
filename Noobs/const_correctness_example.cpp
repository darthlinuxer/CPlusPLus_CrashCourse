// This file demonstrates the importance of const correctness in C++.
// Why this is the right way:
// - It ensures that functions do not modify objects that are meant to be read-only.
// - It improves code readability and prevents unintended side effects.
// How a noob might do it:
// - A noob might omit const, leading to potential bugs and less maintainable code.

#include <iostream>
#include <vector>

// Demonstrating const correctness by marking the vector parameter as const
void printVector(const std::vector<int> &arr) {
    for (const auto &x : arr) {
        std::cout << x << '\n';
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);
    return 0;
}

/* Expected Output:
1
2
3
4
5
*/