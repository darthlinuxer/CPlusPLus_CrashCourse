#include <iostream>
#include <string>

class Person
{
    std::string name;
    std::string surname;
    int age;

    // mutable allows the member to be modified even in a const object.
    mutable int accessCount; // Tracks how many times introduce() is called, even for const objects

public:
    // what happens if you don't use inline?
    // If you don't use inline, you need to define it in the source file.
    // It is a good practice to use inline for static members to avoid multiple definitions in different translation units.
    static inline unsigned int objectCount = 0; // Static member to count the number of Person objects created
    // Default constructor
    Person() : name(""), surname(""), age(0), accessCount(0)
    {
        std::cout << "Default constructor called\n";
        objectCount++; // Increment the object count when a new object is created
    }

    // Parameterized constructor
    Person(const std::string &name, const std::string &surname, int age)
        : name(name), surname(surname), age(age), accessCount(0)
    {
        std::cout << "Parameterized constructor called\n";
        objectCount++; // Increment the object count when a new object is created
    }

#pragma region DefaultMethodsCompilerWrites
    // If you don't write these methods, the compiler will generate them for you.

    // Copy constructor
    Person(const Person &other) : name(other.name), surname(other.surname), age(other.age), accessCount(other.accessCount) {}

    // Move constructor
    Person(Person &&other) noexcept
        : name(std::move(other.name)), surname(std::move(other.surname)), age(other.age), accessCount(other.accessCount)
    {
        other.age = 0;         // Reset the moved-from object's age
        other.accessCount = 0; // Reset the moved-from object's access count
    }

    // Copy assignment operator
    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            name = other.name;
            surname = other.surname;
            age = other.age;
            accessCount = other.accessCount; // Copy the access count
        }
        return *this;
    }

    // Move assignment operator
    Person &operator=(Person &&other) noexcept
    {
        if (this != &other)
        {
            name = std::move(other.name);
            surname = std::move(other.surname);
            age = other.age;
            accessCount = other.accessCount; // Move the access count
            // Reset the moved-from object's state
            // This is optional, but it can help avoid dangling references or invalid states.
            other.age = 0;         // Reset the moved-from object's age
            other.accessCount = 0; // Reset the moved-from object's access count
        }
        return *this;
    }

    // Destructor = default means the compiler will generate a default destructor for you.
    // ~Person() = default;
    ~Person() {
        std::cout << "Destructor called for " << name << " " << surname << "\n";
        --objectCount; // Decrement the object count when an object is destroyed
    }

#pragma endregion DefaultMethodsCompilerWrites

    // Getters
    // These are not necessary, but they are good practice to have.
    // const means that this method does not modify the object.
    // It allows you to call this method on const objects.
    // if you don't write const what happens ?
    // const Person person("John", "Doe", 30);
    // person.getName(); // Error: 'getName' is not a member of 'const Person'
    // person.setName("John"); // Error: 'setName' is not a member of 'const Person'
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    int getAge() const { return age; }
    int getAccessCount() const { return accessCount; } // Accessor for accessCount

    // Setters
    void setName(const std::string &newName) { name = newName; }
    void setSurname(const std::string &newSurname) { surname = newSurname; }
    void setAge(int newAge) { age = newAge; }

    // Setters returning a Pointer
    //  This is a less efficient way to return the current object.
    //  It is not recommended to use this method for chaining calls.
    Person *changeName(const std::string &newName)
    {
        name = newName;
        return this;
    }

    Person *changeSurname(const std::string &newSurname)
    {
        surname = newSurname;
        return this;
    }

    Person *changeAge(const int &newAge)
    {
        age = newAge;
        return this;
    }

    // Setters returning a Reference
    //  This is a more efficient way to return the current object.
    //  It is recommended to use this method for chaining calls.
    //  It allows you to call the method on the current object and return a reference to it.
    Person &changeNameByRef(const std::string &newName)
    {
        name = newName;
        return *this; // Return the current object directly to allow method chaining.
    }

    Person &changeSurnameByRef(const std::string &newSurname)
    {
        surname = newSurname;
        return *this;
    }

    Person &changeAgeByRef(const int &newAge)
    {
        age = newAge;
        return *this;
    }

    void introduce() const
    {
        ++accessCount; // Increment access count
        std::cout << "Hi, I'm " << name << " " << surname << " and I'm " << age << " years old.\n"
                  << "I was called " << accessCount << " times.\n";
    }
};

// if you don't use inline in the variable declaration, you need to initialize it here.
// unsigned int Person::objectCount = 0; // Initialize the static member outside the class

int main()
{
    Person person("John", "Doe", 30); // Create a Person object
    person.introduce();

    Person person2 = person;                          // Copy constructor is called
    person2.setName("John Copy");                     // using the setter
    person2.changeSurname("Doe Copy")->changeAge(31); // using pointers for chain call
    person2.introduce();
    person.introduce(); // person is still valid

    Person person3 = std::move(person);                                                       // Move constructor is called
    person3.changeNameByRef("John Moved").changeSurnameByRef("Doe Moved").changeAgeByRef(32); // using references for chain call
    person3.introduce();
    person.introduce(); // person is in a valid but unspecified state

    Person person4;                          // Default constructor is called
    person4 = person2;                       // Copy assignment operator is called
    person4.setName("John");                 // Modify the assigned object
    person4.setSurname("Doe Copy Assigned"); // Modify the assigned object
    person4.setAge(33);                      // Modify the assigned object
    person4.introduce();
    person2.introduce(); // person2 is still valid

    Person person5;                                                                     // Default constructor is called
    person5 = std::move(person3);                                                       // Move assignment operator is called
    person5.changeNameByRef("John").changeSurnameByRef("Doe Move Assigned").setAge(34); // Modify the assigned object
    person5.introduce();
    person3.introduce(); // person3 is in a valid but unspecified state

    const Person constPerson("John", "Rambo", 30); // Create a const Person object
    constPerson.introduce();
    constPerson.introduce();
    constPerson.introduce(); // Call introduce() on a const object

    std::cout << "Total Person objects created: " << Person::objectCount << "\n"; // Access static member
    return 0;
}

/*
Parameterized constructor called
Hi, I'm John Doe and I'm 30 years old.
I was called 1 times.
Hi, I'm John Copy Doe Copy and I'm 31 years old.
I was called 2 times.
Hi, I'm John Doe and I'm 30 years old.
I was called 2 times.
Hi, I'm John Moved Doe Moved and I'm 32 years old.
I was called 3 times.
Hi, I'm   and I'm 0 years old.
I was called 1 times.
Default constructor called
Hi, I'm John Doe Copy Assigned and I'm 33 years old.
I was called 3 times.
Hi, I'm John Copy Doe Copy and I'm 31 years old.
I was called 3 times.
Default constructor called
Hi, I'm John Doe Move Assigned and I'm 34 years old.
I was called 4 times.
Hi, I'm   and I'm 0 years old.
I was called 1 times.
Parameterized constructor called
Hi, I'm John Rambo and I'm 30 years old.
I was called 1 times.
Hi, I'm John Rambo and I'm 30 years old.
I was called 2 times.
Hi, I'm John Rambo and I'm 30 years old.
I was called 3 times.
Total Person objects created: 4
*/