// Demonstrates the use of `std::string` instead of C-style strings.

#include <iostream>
#include <string> // For `std::string`.

int main() {
    // Use `std::string` for safer and more convenient string handling.
    std::string greeting = "Hello, ";
    std::string name = "World";

    // Concatenate strings.
    std::string message = greeting + name + "!";
    std::cout << message << "\n";

    // Access individual characters.
    std::cout << "The first character is: " << message[0] << "\n";

    return 0;
}