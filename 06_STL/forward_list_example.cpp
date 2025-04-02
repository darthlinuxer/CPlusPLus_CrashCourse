#include <iostream>
#include <forward_list>

int main() {
    // Create a forward_list
    std::forward_list<int> fl = {1, 2, 3};

    // Insert elements
    fl.push_front(0); // Add 0 to the front

    // Print elements
    std::cout << "Forward list elements: ";
    for (int x : fl) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Forward list elements: 0 1 2 3
*/