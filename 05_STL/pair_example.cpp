#include <iostream>
#include <utility>

int main() {
    // Create a pair with an int and a string
    std::pair<int, std::string> myPair(1, "Hello");

    // Access and print pair elements
    std::cout << "Pair: (" << myPair.first << ", " << myPair.second << ")\n";

    return 0;
}

/*
Expected Output:
Pair: (1, Hello)
*/