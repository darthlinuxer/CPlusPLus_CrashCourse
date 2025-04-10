#include <iostream>
#include <string>

// Generic template
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic value: " << value << "\n";
    }
};

// Specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "String value: " << value << "\n";
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42);

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello, Specialization!");

    return 0;
}

/*
Output:
Generic value: 42
String value: Hello, Specialization!
*/
