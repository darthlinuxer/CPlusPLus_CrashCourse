#include <iostream>

// Variadic template function to print all arguments
template <typename T, typename... Args>
void printAll(T first, Args... rest) {
    std::cout << first << " ";
    if constexpr (sizeof...(rest) > 0) {
        printAll(rest...);
    }
}

int main() {
    printAll(1, 2.5, "Hello", 'A');
    return 0;
}

/*
Output:
1 2.5 Hello A
*/
