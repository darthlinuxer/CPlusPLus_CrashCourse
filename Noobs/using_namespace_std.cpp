// This file demonstrates the use of "using namespace std" and its alternatives in C++.
// Why this is the right way:
// - Avoiding "using namespace std" globally prevents potential name conflicts and improves code clarity.
// - Using specific declarations (e.g., using std::string) keeps the code clean and explicit.
// How a noob might do it:
// - A noob might use "using namespace std" globally, leading to potential conflicts and less readable code.

#include <iostream>
#include <string>

// Demonstrating the use of "using namespace std" and its alternatives
void usingNamespaceStd() {
    // Avoiding "using namespace std" globally
    using std::string;
    string s{"hello, world!"};
    std::cout << s << std::endl;
}

int main() {
    usingNamespaceStd();
    return 0;
}

/* Expected Output:
hello, world!
*/