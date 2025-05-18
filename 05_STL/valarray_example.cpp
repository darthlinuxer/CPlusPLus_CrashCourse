#include <iostream>
#include <valarray>

int main() {
    // Create a valarray
    std::valarray<int> v = {1, 2, 3, 4, 5};

    // Perform element-wise operations
    std::valarray<int> result = v * 2;

    // Print the result
    std::cout << "Valarray elements after multiplication: ";
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Valarray elements after multiplication: 2 4 6 8 10
*/