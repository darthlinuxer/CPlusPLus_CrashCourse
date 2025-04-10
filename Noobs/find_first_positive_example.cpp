// This file demonstrates the use of std::find_if to locate the first positive element in a container.
// Why this is the right way:
// - It leverages the STL, making the code concise and expressive.
// - It avoids manual iteration, reducing the risk of errors.
// How a noob might do it:
// - A noob might write a manual loop, leading to more verbose and error-prone code.

#include <iostream>
#include <vector>
#include <algorithm>

// Demonstrating the use of std::find_if instead of a manual loop
void findFirstPositive() {
    const std::vector<int> data = {-1, -3, -5, 8, 15, -1};

    // Using std::find_if to find the first positive element
    const auto isPositive = [](const auto &x) { return x > 0; };
    auto firstPosIt = std::find_if(data.cbegin(), data.cend(), isPositive);

    if (firstPosIt != data.cend()) {
        std::cout << "First positive element: " << *firstPosIt << std::endl;
    } else {
        std::cout << "No positive elements found." << std::endl;
    }
}

int main() {
    findFirstPositive();
    return 0;
}

/* Expected Output:
First positive element: 8
*/