#include <iostream>
#include <string>
#include <vector>

// Template function to find the maximum of two values.
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template class to demonstrate generic programming with classes.
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() const { return value; }
    void setValue(T val) { value = val; }
};

// Template specialization for a specific type (e.g., std::string).
template <>
class Box<std::string> {
private:
    std::string value;
public:
    Box(std::string val) : value(val) {}
    std::string getValue() const { return "String value: " + value; }
    void setValue(std::string val) { value = val; }
};

// Variadic template function to calculate the sum of multiple arguments.
template <typename... Args>
auto sum(Args... args) {
    return (args + ...); // Fold expression (C++17 feature)
}

int main() {
    // Demonstrating template function.
    std::cout << "Max of 3 and 7: " << findMax(3, 7) << "\n";
    std::cout << "Max of 3.5 and 2.1: " << findMax(3.5, 2.1) << "\n";
    std::cout << "Max of 'a' and 'z': " << findMax('a', 'z') << "\n";

    // Demonstrating template class.
    Box<int> intBox(42);
    std::cout << "Box value (int): " << intBox.getValue() << "\n";

    Box<std::string> strBox("Hello, Templates!");
    std::cout << strBox.getValue() << "\n";

    // Demonstrating variadic template function.
    std::cout << "Sum of 1, 2, 3, 4: " << sum(1, 2, 3, 4) << "\n";
    std::cout << "Sum of 1.1, 2.2, 3.3: " << sum(1.1, 2.2, 3.3) << "\n";

    return 0;
}