/*
Friend Functions in C++
-----------------------
Friend functions are a feature in C++ that allow a non-member function to access the private and protected members of a class. This is achieved by declaring the function as a friend within the class definition.

Why is it needed?
-----------------
In some cases, it is necessary for a function to access the private data of a class without being a member of that class. For example, when implementing certain operations that require access to private members but do not logically belong to the class itself, friend functions provide a way to achieve this while maintaining encapsulation.

When to use it?
---------------
- When a function needs to operate on private data of a class but does not logically belong as a member of the class.
- When implementing operator overloading for non-member operators that require access to private members.
- When designing utility functions that need access to the internals of a class.

However, use friend functions judiciously, as they break the encapsulation principle by exposing private members to external functions. Overusing them can make the code harder to maintain and understand.
*/

#include <iostream>
#include <string>

class ExampleClass {
private:
    std::string name;
    int value;

public:
    ExampleClass(const std::string& name, int value) : name(name), value(value) {}

    // Declare a friend function
    friend void displayDetails(const ExampleClass& obj);
};

// Friend function definition
void displayDetails(const ExampleClass& obj) {
    std::cout << "Friend Function: Name = " << obj.name << ", Value = " << obj.value << std::endl;
}

int main() {
    ExampleClass example("TestObject", 42);

    // Use the friend function
    displayDetails(example);
    return 0;
}

/*
Output:
Friend Function: Name = TestObject, Value = 42
*/