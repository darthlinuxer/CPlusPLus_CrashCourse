#include <iostream>
#include <string>
#include <utility> // For std::move

// A class demonstrating private constructors and prevention of object copying.
class UniqueClass {
private:
    std::string name;
    int age;

    // Private default constructor to prevent creating objects without parameters.
    UniqueClass() = default;

public:
    // Constructor using an initializer list (best practice in C++).
    UniqueClass(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Constructor called for " << this->name << std::endl;
    }

    // Destructor in C++ is explicitly defined to handle cleanup.
    ~UniqueClass() {
        std::cout << "Destructor called for " << this->name << std::endl;
    }

    // Copy Constructor
    UniqueClass(const UniqueClass& other) : name(other.name), age(other.age) {
        std::cout << "Copy Constructor called for " << this->name << std::endl;
    }

    // Move Constructor
    UniqueClass(UniqueClass&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move Constructor called for " << this->name << std::endl;
        other.age = 0; // Reset the moved-from object's age
    }

    // Copy Assignment Operator
    UniqueClass& operator=(const UniqueClass& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            std::cout << "Copy Assignment Operator called for " << this->name << std::endl;
        }
        return *this;
    }

    // Move Assignment Operator
    UniqueClass& operator=(UniqueClass&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            age = other.age;
            other.age = 0; // Reset the moved-from object's age
            std::cout << "Move Assignment Operator called for " << this->name << std::endl;
        }
        return *this;
    }

    // A method to display the object's data.
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Static factory method to create objects.
    // This is useful when the default constructor is private.
    static UniqueClass create(const std::string& name, int age) {
        return UniqueClass(name, age);
    }
};

int main() {
    std::cout << "============================" << std::endl;
    std::cout << "Creating an object using the public constructor." << std::endl;
    UniqueClass obj1("John Doe", 30);
    obj1.display(); // Name: John Doe, Age: 30

    std::cout << "Creating an object using the static factory method." << std::endl;
    UniqueClass obj2 = UniqueClass::create("Jane Doe", 25);
    obj2.display(); // Name: Jane Doe, Age: 25

    std::cout << "Using the copy constructor." << std::endl;
    UniqueClass obj3 = obj1;
    obj3.display(); // Name: John Doe, Age: 30
    std::cout << "obj1 remains unchanged:" << std::endl;
    obj1.display(); // Name: John Doe, Age: 30
    
    std::cout << "Using the copy assignment operator." << std::endl;
    obj3 = obj2;
    obj3.display(); // Name: Jane Doe, Age: 25
    std::cout << "obj2 remains unchanged:" << std::endl;
    obj2.display(); // Name: Jane Doe, Age: 25
 
    std::cout << "Using the move constructor." << std::endl;
    UniqueClass obj4 = std::move(obj1);
    obj4.display(); // Name: John Doe, Age: 30
    std::cout << "obj1 is in a valid but unspecified state after being moved:" << std::endl;
    obj1.display(); // Name: , Age: 0 (or some other unspecified state)

    std::cout << "Using the move assignment operator." << std::endl;
    obj4 = std::move(obj2);
    obj4.display(); // Name: Jane Doe, Age: 25
    std::cout << "obj2 is in a valid but unspecified state after being moved:" << std::endl;
    obj2.display(); // Name: , Age: 0 (or some other unspecified state)

    std::cout << "End of main function." << std::endl;

    return 0;
}

/*
============================
Creating an object using the public constructor.   
Constructor called for John Doe
Name: John Doe, Age: 30
Creating an object using the static factory method.
Constructor called for Jane Doe
Name: Jane Doe, Age: 25
Using the copy constructor.
Copy Constructor called for John Doe
Name: John Doe, Age: 30
obj1 remains unchanged:
Name: John Doe, Age: 30
Using the copy assignment operator.
Copy Assignment Operator called for Jane Doe
Name: Jane Doe, Age: 25
obj2 remains unchanged:
Name: Jane Doe, Age: 25
Using the move constructor.
Move Constructor called for John Doe
Name: John Doe, Age: 30
obj1 is in a valid but unspecified state after being moved:
Name: , Age: 0
Using the move assignment operator.
Move Assignment Operator called for Jane Doe
Name: Jane Doe, Age: 25
obj2 is in a valid but unspecified state after being moved:
Name: , Age: 0
End of main function.
Destructor called for Jane Doe
Destructor called for Jane Doe
Destructor called for
Destructor called for
*/