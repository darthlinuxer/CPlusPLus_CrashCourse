#include <iostream>
#include <list>

int main() {
    // Create a list with initial elements
    std::list<int> lst = {1, 2, 3};

    // Add elements to the front and back
    lst.push_back(4);  // Add 4 to the back
    lst.push_front(0); // Add 0 to the front

    // Print all elements
    std::cout << "List elements: ";
    for (int x : lst) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
List elements: 0 1 2 3 4
*/