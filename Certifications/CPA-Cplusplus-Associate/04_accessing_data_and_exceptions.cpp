// Exam block #4: Accessing data and dealing with exceptions
// converting values of different types
// strings: declarations, initializations, assignments
// string as an example of object: introducing methods and properties
// namespaces: using and declaring
// dealing with exceptions

#include <iostream>
#include <string>
#include <stdexcept>

namespace myspace {
    void hello() {
        std::cout << "Hello from myspace!" << std::endl;
    }
}

int main() {
    // Type conversion
    double d = 9.99;
    int i = static_cast<int>(d);
    std::cout << "Converted double to int: " << i << std::endl;
    // Strings
    std::string s1 = "Hello";
    std::string s2(s1);
    s2 += ", World!";
    std::cout << s2 << " (length: " << s2.length() << ")" << std::endl;
    // Namespace
    myspace::hello();
    // Exception handling
    try {
        throw std::runtime_error("An error occurred");
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }
    return 0;
}

// Output:
// Converted double to int: 9
// Hello, World! (length: 13)
// Hello from myspace!
// Caught exception: An error occurred
