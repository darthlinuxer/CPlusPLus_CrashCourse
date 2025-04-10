#include <iostream>

// Compile-time factorial calculation
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// Base case
template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Factorial of 5: " << Factorial<5>::value << "\n";
    std::cout << "Factorial of 0: " << Factorial<0>::value << "\n";
    return 0;
}

/*
Output:
Factorial of 5: 120
Factorial of 0: 1
*/
