#include <iostream>
#include <string>

class Person {
    std::string name;
    int age;

public:
    // Default constructor
    Person() : name(""), age(0) {}

    // Parameterized constructor
    Person(const std::string& name, int age)
        : name(name), age(age) {}

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Move constructor
    Person(Person&& other) noexcept
        : name(std::move(other.name)), age(other.age) {
        other.age = 0; // Reset the moved-from object's age
    }

    // Copy assignment operator
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Move assignment operator
    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            age = other.age;
            other.age = 0; // Reset the moved-from object's age
        }
        return *this;
    }

    // Destructor
    ~Person() {}

    // Method to modify name and age
    void modify(const std::string& newName, int newAge) {
        name = newName;
        age = newAge;
    }

    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Person person("John", 30); // Create a Person object
    person.introduce();

    Person person2 = person; // Copy constructor is called
    person2.modify("John Copy", 31); // Modify the copied object
    person2.introduce();
    person.introduce(); // person is still valid

    Person person3 = std::move(person); // Move constructor is called
    person3.modify("John Moved", 32); // Modify the moved object
    person3.introduce();
    person.introduce(); // person is in a valid but unspecified state

    Person person4; // Default constructor is called
    person4 = person2; // Copy assignment operator is called
    person4.modify("John Copy Assigned", 33); // Modify the assigned object
    person4.introduce();
    person2.introduce(); // person2 is still valid

    Person person5; // Default constructor is called
    person5 = std::move(person3); // Move assignment operator is called
    person5.modify("John Move Assigned", 34); // Modify the assigned object
    person5.introduce();
    person3.introduce(); // person3 is in a valid but unspecified state

    return 0;
}

/*
Hi, I'm John and I'm 30 years old.
Hi, I'm John Copy and I'm 31 years old.
Hi, I'm John and I'm 30 years old.
Hi, I'm John Moved and I'm 32 years old.
Hi, I'm  and I'm 0 years old.
Hi, I'm John Copy Assigned and I'm 33 years old.
Hi, I'm John Copy and I'm 31 years old.
Hi, I'm John Move Assigned and I'm 34 years old.
Hi, I'm  and I'm 0 years old.
*/