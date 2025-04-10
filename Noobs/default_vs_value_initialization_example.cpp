// This file demonstrates the difference between default initialization and value initialization in C++.
// Why this is the right way:
// - It clearly shows how uninitialized variables can lead to undefined behavior with default initialization.
// - It highlights the benefits of value initialization, which ensures variables are initialized to default values.
// How a noob might do it:
// - A noob might rely on default initialization without realizing that it leaves variables uninitialized, leading to potential bugs.
// - They might not understand the importance of explicitly initializing variables.

#include <iostream>
#include <string>

// Demonstrating default vs. value initialization
struct S {
    int n, m;
    std::string s;

    S() {
        std::cout << "Default constructor called\n";
    }
};

int main() {
    S defaultInitialized; // Default initialization
    std::cout << "Default initialized: " << defaultInitialized.n << " " << defaultInitialized.m << " \"" << defaultInitialized.s << "\"\n";

    S valueInitialized{}; // Value initialization
    std::cout << "Value initialized: " << valueInitialized.n << " " << valueInitialized.m << " \"" << valueInitialized.s << "\"\n";

    return 0;
}

/* Expected Output:
Default constructor called
Default initialized: <garbage> <garbage> ""
Value initialized: 0 0 ""
*/