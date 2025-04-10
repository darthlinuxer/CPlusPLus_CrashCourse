#include <iostream>
#include <valarray>

int main() {
    std::valarray<int> v = {1, 2, 3};
    std::valarray<int> result = v + 1;

    std::cout << "Valarray after adding 1: ";
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Valarray after adding 1: 2 3 4
*/