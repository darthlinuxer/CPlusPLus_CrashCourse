#include <iostream>
#include <string>
#include <utility> // For std::move

// A class demonstrating private constructors and prevention of object copying.
class UniqueClass {
private:
    std::string name;
    int age;
    int* data; // Dynamically allocated resource

    // Private default constructor to prevent creating objects without parameters.
    UniqueClass() = default;

public:
    // Constructor using an initializer list (best practice in C++).
    UniqueClass(const std::string& name, int age) : name(name), age(age) {
        data = new int[100]; // Allocate some resource
        std::cout << "Constructor called for " << this->name << std::endl;
    }

    // Destructor in C++ is explicitly defined to handle cleanup.
    ~UniqueClass() {
        delete[] data; // Free the allocated resource
        std::cout << "Destructor called for " << this->name << std::endl;
    }

    // Delete the copy constructor to prevent copying of the object.
    UniqueClass(const UniqueClass&) = delete;

    // Delete the copy assignment operator to prevent assignment.
    UniqueClass& operator=(const UniqueClass&) = delete;

    // Move constructor to transfer ownership of resources.
    UniqueClass(UniqueClass&& other) noexcept
        : name(std::move(other.name)), age(other.age), data(other.data) {
        other.data = nullptr; // Nullify the source's pointer
        std::cout << "Move constructor called for " << this->name << std::endl;
    }

    // Move assignment operator to transfer ownership of resources.
    UniqueClass& operator=(UniqueClass&& other) noexcept { //noexcept means this function will not throw exceptions
        if (this != &other) {
            delete[] data; // Free existing resource
            name = std::move(other.name);
            age = other.age;
            data = other.data;
            other.data = nullptr; // Nullify the source's pointer
            std::cout << "Move assignment operator called for " << this->name << std::endl;
        }
        return *this;
    }

    // A method to display the object's data.
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Static factory method to create objects.
    static UniqueClass create(const std::string& name, int age) {
        return UniqueClass(name, age);
    }
};

int main() {
    std::cout << std::string(50, '*') << std::endl;
    std::cout << "Creating an object using the public constructor." << std::endl;
    UniqueClass obj1("John Doe", 30);
    obj1.display();

    std::cout << "Creating an object using the static factory method." << std::endl;
    UniqueClass obj2 = UniqueClass::create("Jane Doe", 25);
    obj2.display();

    std::cout << "Demonstrating move constructor." << std::endl;
    UniqueClass obj3 = std::move(obj1); // Move obj1 to obj3
    obj3.display();

    // Demonstrating move assignment operator.
    std::cout << "Demonstrating move assignment operator." << std::endl;
    obj2 = std::move(obj3); // Move obj3 to obj2
    obj2.display();
    obj3.display(); // obj3 is now in a valid but unspecified state

    // Uncommenting the following lines will cause compilation errors
    // because copying is disabled.
    // UniqueClass obj4 = obj2; // Error: Copy constructor is deleted.
    // obj2 = obj1;            // Error: Copy assignment operator is deleted.

    std::cout << "End of main function." << std::endl;

    return 0;
}

/*
PS C:\Users\CCHAVES\Dev\CPlusPLus_CrashCourse\build\binaries\Debug> ./11_CPlusPlusUniqueness_MoveConstructors.exe
**************************************************
Creating an object using the public constructor.
Constructor called for John Doe
Name: John Doe, Age: 30
Creating an object using the static factory method.
Constructor called for Jane Doe
Name: Jane Doe, Age: 25
Demonstrating move constructor.
Move constructor called for John Doe
Name: John Doe, Age: 30
Demonstrating move assignment operator.
Move assignment operator called for John Doe
Name: John Doe, Age: 30
Name: , Age: 30
End of main function.
Destructor called for
Destructor called for John Doe
Destructor called for
*/