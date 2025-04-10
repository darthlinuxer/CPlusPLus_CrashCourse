// This file demonstrates the use of range-based for loops in C++.
// Why this is the right way:
// - It simplifies iteration over containers, improving readability.
// - It reduces the risk of off-by-one errors compared to index-based loops.
// How a noob might do it:
// - A noob might use an index-based loop, making the code more verbose and error-prone.

#include <iostream>
#include <vector>

// Demonstrating range-based for loop instead of index-based loop
void trainModel(const std::vector<int> &data) {
    for (const auto &x : data) {
        std::cout << "Processing: " << x << std::endl;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    trainModel(data);
    return 0;
}

/* Expected Output:
Processing: 1
Processing: 2
Processing: 3
Processing: 4
Processing: 5
*/