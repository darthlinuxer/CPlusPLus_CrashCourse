#include <iostream>

int main() {
    int vec[] = {1, 2, 3, 4, 5};
    int size = 5;

    // Transform: Multiply each element by 2
    for (int i = 0; i < size; ++i) {
        vec[i] *= 2;
    }
    std::cout << "After transform: ";
    for (int i = 0; i < size; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    // Accumulate: Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += vec[i];
    }
    std::cout << "Sum: " << sum << "\n";

    // Find: Search for the element 6
    bool found = false;
    for (int i = 0; i < size; ++i) {
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
Expected Output:
After transform: 2 4 6 8 10 
Sum: 30
Found: 6
*/