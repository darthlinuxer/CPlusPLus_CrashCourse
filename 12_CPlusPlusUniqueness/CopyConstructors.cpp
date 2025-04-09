#include <iostream>
#include <string>

// A class demonstrating the need for a custom copy constructor.
class ResourceClass
{
private:
    std::string *name; // Dynamically allocated resource
    int age;

public:
    // Constructor using an initializer list (best practice in C++).
    ResourceClass(const std::string &name, int age) : name(new std::string(name)), age(age)
    {
        std::cout << "Constructor called for " << *this->name << " age:" << this->age << std::endl;
    }

    // Custom copy constructor to perform a deep copy.
    ResourceClass(const ResourceClass &other) : name(new std::string(*other.name)), age(other.age)
    {
        std::cout << "Copy constructor called for " << *this->name << " age:" << this->age << std::endl;
    }

    // Custom assignment operator
    ResourceClass &operator=(const ResourceClass &other)
    {
        if (this == &other)
        {
            return *this; // Handle self-assignment
        }

        // Clean up the existing resource
        delete name;

        // Perform a deep copy
        name = new std::string(*other.name);
        age = other.age;

        std::cout << "Assignment operator called for " << *name << " age:" << age << std::endl;

        return *this;
    }

    // Destructor to release the dynamically allocated resource.
    ~ResourceClass()
    {
        std::cout << "Destructor called for " << *name << std::endl;
        delete name;
    }

    // A method to display the object's data.
    void display() const
    {
        std::cout << "Display method called -> Name: " << *name << ", Age: " << age << std::endl;
    }
};

int main()
{
    std::cout << std::string(50, '*') << std::endl;
    ResourceClass obj1("John Doe", 30);
    obj1.display();

    std::cout << "Creating a copy of the object using the copy constructor.\n";
    ResourceClass obj2 = obj1; // This will call the copy constructor
    obj2.display();

    std::cout << "Modifying the original object to show that the copy is independent.\n";
    std::cout << "Modifying obj1..." << std::endl;
    obj1 = ResourceClass("Jane Doe", 25); // This will call the assignment operator
    obj1.display();
    obj2.display(); // obj2 remains unchanged

    std::cout << "End of main function." << std::endl;

    return 0;
}

/*
**************************************************
Constructor called for John Doe age:30
Display method called -> Name: John Doe, Age: 30
Creating a copy of the object using the copy constructor.
Copy constructor called for John Doe age:30
Display method called -> Name: John Doe, Age: 30
Modifying the original object to show that the copy is independent.
Modifying obj1...
Constructor called for Jane Doe age:25
Assignment operator called for Jane Doe age:25
Destructor called for Jane Doe
Display method called -> Name: Jane Doe, Age: 25
Display method called -> Name: John Doe, Age: 30
End of main function.
Destructor called for John Doe
Destructor called for Jane Doe
*/