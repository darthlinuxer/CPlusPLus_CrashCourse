#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> uset = {1, 2};
    uset.insert(3);

    std::cout << "Unordered set: ";
    for (int x : uset) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Unordered set: (order may vary) 1 2 3
*/