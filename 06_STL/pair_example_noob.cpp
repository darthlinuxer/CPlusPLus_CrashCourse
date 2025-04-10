#include <iostream>
#include <string>

class NoobPair {
public:
    int first;
    std::string second;

    NoobPair(int f, const std::string& s) : first(f), second(s) {}
};

int main() {
    // Create a pair with an int and a string
    NoobPair myPair(1, "Hello");

    // Access and print pair elements
    std::cout << "Pair: (" << myPair.first << ", " << myPair.second << ")\n";

    return 0;
}

/*
Expected Output:
Pair: (1, Hello)
*/