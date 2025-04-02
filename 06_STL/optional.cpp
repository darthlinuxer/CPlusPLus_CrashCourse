// Demonstrates the use of `std::optional` for optional values.

#include <iostream>
#include <optional> // For `std::optional`.

std::optional<int> findValue(bool condition) {
    if (condition) {
        return 42; // Return a value if the condition is true.
    }
    return std::nullopt; // Return no value.
}

int main() {
    auto result = findValue(true);
    if (result) {
        std::cout << "Found value: " << *result << "\n";
    } else {
        std::cout << "No value found.\n";
    }

    return 0;
}