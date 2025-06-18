// Exam block #8: The Basics of Functions (Exceptions)
// what is an exception, catching and throwing exceptions
// different classes and hierarchy of exceptions, defining your own exceptions

#include <iostream>
#include <stdexcept>

class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception!";
    }
};

void mayThrow(bool trigger) {
    if (trigger) throw MyException();
    throw std::runtime_error("Standard runtime error");
}

int main() {
    try {
        mayThrow(true);
    } catch (const MyException& ex) {
        std::cout << "Caught: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Standard exception: " << ex.what() << std::endl;
    }
    return 0;
}

// Output:
// Caught: My custom exception!
