// This file demonstrates safe iteration over a container while modifying it.
// Why this is the right way:
// - It avoids undefined behavior by iterating over a copy of the container.
// - It ensures that the original container can be safely modified during iteration.
// How a noob might do it:
// - A noob might iterate directly over the container being modified, leading to undefined behavior.

#include <iostream>
#include <vector>
#include <algorithm>

// Demonstrating safe iteration without modifying the container
void modifyWhileIterating() {
    std::vector<int> v{1, 2, 3, 4};

    // Safely create a copy of the container to iterate over
    std::vector<int> copy = v;
    for (const auto &x : copy) {
        v.push_back(x); // Modify the original container
    }

    // Print the modified container
    for (const auto &x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    modifyWhileIterating();
    return 0;
}

/* Expected Output:
1 2 3 4 1 2 3 4 
*/