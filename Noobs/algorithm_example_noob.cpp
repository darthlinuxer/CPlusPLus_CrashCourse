// A noob's approach to achieve the same functionality without STL
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Transform: Multiply each element by 2
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] = vec[i] * 2;
    }
    std::cout << "After transform: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    // Accumulate: Calculate the sum of all elements
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    std::cout << "Sum: " << sum << "\n";

    // Find: Search for the element 6
    bool found = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == 6) {
            std::cout << "Found: " << vec[i] << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Not found\n";
    }

    return 0;
}

/*
After transform: 2 4 6 8 10 
Sum: 30
Found: 6
*/