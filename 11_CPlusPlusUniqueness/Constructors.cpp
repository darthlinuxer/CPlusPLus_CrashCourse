#include <iostream>
#include <string>

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

    // The copy constructor is a special constructor in C++ that initializes a new object as a copy of an existing object.
    // It is used when an object is passed by value to a function or returned from a function.
    // The default copy constructor performs a shallow copy, which may not be suitable for classes with dynamic memory allocation.
    // Shallow copy means that the new object created is a copy of the original object, but it shares the same memory location for any dynamically allocated resources.
    // This can lead to issues if one object modifies the resource, as the other object will see the changes.
    // To delete the copy constructor add delete to prevent copying of the object.
    UniqueClass(const UniqueClass&) = delete; // Copy constructor is deleted.

    // Move constructor is used to transfer ownership of resources from one object to another.
    // It is used when an object is passed by value to a function or returned from a function, and the object is not needed anymore.
    // The move constructor is more efficient than the copy constructor because it does not create a new copy of the object.
    // It transfers the ownership of the resources from the source object to the destination object.
    // Delete the copy assignment operator to prevent assignment.
    UniqueClass& operator=(const UniqueClass&) = delete; // Copy assignment operator is deleted.

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
    // Creating an object using the public constructor.
    UniqueClass obj1("John Doe", 30);
    obj1.display();

    // Creating an object using the static factory method.
    UniqueClass obj2 = UniqueClass::create("Jane Doe", 25);
    obj2.display();

    // Uncommenting the following lines will cause compilation errors
    // because copying is disabled.
    // UniqueClass obj3 = obj1; // Error: Copy constructor is deleted.
    // obj2 = obj1;            // Error: Copy assignment operator is deleted.

    std::cout << "End of main function." << std::endl;

    return 0;
}

/*
Constructor called for John Doe
Name: John Doe, Age: 30
Constructor called for Jane Doe
Name: Jane Doe, Age: 25
End of main function.
Destructor called for Jane Doe
Destructor called for John Doe
*/