/*
This example demonstrates several important C++ concepts related to constructors and object management. These include:

1. **Member Initializer List**: A way to initialize class members directly in the constructor, which is more efficient and often required for const or reference members.
2. **Explicit Keyword**: Used to prevent implicit conversions when a constructor takes a single argument.
3. **Default Keyword**: Allows you to explicitly specify that a constructor or destructor should use the compiler-generated default implementation.
4. **Copy and Move Semantics**: Includes copy constructors, move constructors, copy assignment operators, and move assignment operators to manage resource ownership and optimize performance.

This program is designed to help a senior C# developer understand these C++ features by providing practical examples and explanations.
*/

#include <iostream>
#include <string>

// A class demonstrating various C++ keywords and concepts for constructors.
class ExampleClass {
private:
    std::string name;
    int age;

public:
    // Default constructor using the 'default' keyword.
    ExampleClass() = default;

    // Constructor using a member initializer list (best practice in C++).
    ExampleClass(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Member initializer list constructor called for " << this->name << std::endl;
    }

    // Explicit constructor to prevent implicit conversions.
    explicit ExampleClass(int age) : name("Default Name"), age(age) {
        std::cout << "Explicit constructor called with age: " << this->age << std::endl;
    }

    // Copy constructor.
    ExampleClass(const ExampleClass& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called for " << this->name << std::endl;
    }

    // Move constructor.
    ExampleClass(ExampleClass&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move constructor called for " << this->name << std::endl;
        other.age = 0; // Reset the moved-from object's age
    }

    // Copy assignment operator.
    ExampleClass& operator=(const ExampleClass& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            std::cout << "Copy assignment operator called for " << this->name << std::endl;
        }
        return *this;
    }

    // Move assignment operator.
    ExampleClass& operator=(ExampleClass&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            age = other.age;
            other.age = 0; // Reset the moved-from object's age
            std::cout << "Move assignment operator called for " << this->name << std::endl;
        }
        return *this;
    }

    // Destructor.
    ~ExampleClass() {
        std::cout << "Destructor called for " << this->name << std::endl;
    }

    // A method to display the object's data.
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    std::cout << "============================" << std::endl;
    std::cout << "Default constructor example." << std::endl;
    ExampleClass obj1;

    std::cout << "Member initializer list constructor example." << std::endl;
    ExampleClass obj2("John Doe", 30);
    obj2.display();

    std::cout << "Explicit constructor example." << std::endl;
    ExampleClass obj3(25); // Allowed because the constructor is explicit
    obj3.display();

    std::cout << "Copy constructor example." << std::endl;
    ExampleClass obj4 = obj2;
    obj4.display();

    std::cout << "Move constructor example." << std::endl;
    ExampleClass obj5 = std::move(obj2);
    obj5.display();

    std::cout << "Copy assignment operator example." << std::endl;
    obj4 = obj3;
    obj4.display();

    std::cout << "Move assignment operator example." << std::endl;
    obj5 = std::move(obj3);
    obj5.display();

    std::cout << "End of main function." << std::endl;

    return 0;
}

/*
Output:
============================
Default constructor example.
Member initializer list constructor example.
Member initializer list constructor called for John Doe
Name: John Doe, Age: 30
Explicit constructor example.
Explicit constructor called with age: 25
Name: Default Name, Age: 25
Copy constructor example.
Copy constructor called for John Doe
Name: John Doe, Age: 30
Move constructor example.
Move constructor called for John Doe
Name: John Doe, Age: 30
Copy assignment operator example.
Copy assignment operator called for Default Name
Name: Default Name, Age: 25
Move assignment operator example.
Move assignment operator called for Default Name
Name: Default Name, Age: 25
End of main function.
Destructor called for Default Name
Destructor called for Default Name
Destructor called for
Destructor called for
Destructor called for
*/