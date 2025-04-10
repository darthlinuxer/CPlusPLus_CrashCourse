// This file demonstrates the use of structured bindings in C++.
// Why this is the right way:
// - It simplifies code by allowing multiple variables to be declared in a single statement.
// - It improves readability when working with structured data like pairs or maps.
// How a noob might do it:
// - A noob might manually extract values, leading to more verbose and error-prone code.

#include <iostream>
#include <unordered_map>
#include <string>

// Demonstrating structured bindings
void loopMapItems() {
    std::unordered_map<std::string, std::string> colors = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    };

    // Using structured bindings to iterate over the map
    for (const auto &[name, hex] : colors) {
        std::cout << "name: " << name << ", hex: " << hex << '\n';
    }
}

int main() {
    loopMapItems();
    return 0;
}

/* Expected Output:
name: RED, hex: #FF0000
name: GREEN, hex: #00FF00
name: BLUE, hex: #0000FF
*/