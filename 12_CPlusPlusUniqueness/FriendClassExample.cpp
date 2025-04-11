/*
Friend Classes in C++
----------------------
Friend classes are a feature in C++ that allow one class to access the private and protected members of another class. This is achieved by declaring the friend class within the class whose members need to be accessed.

Why is it needed?
-----------------
In certain scenarios, it is necessary for one class to have access to the internal details of another class to perform specific operations. For example, a helper class might need to modify private data of another class to implement functionality that cannot be achieved through public interfaces alone. Friend classes provide a controlled way to grant such access without exposing the private members to the entire program.

When to use it?
---------------
- When two classes are tightly coupled, and one class needs to access the private members of another class to perform its operations.
- When you want to encapsulate functionality in a separate class but still need access to the internals of another class.
- When designing helper or utility classes that require access to private data of the main class.

However, use friend classes sparingly, as they break the encapsulation principle by exposing private members to another class. Overusing them can make the code harder to maintain and understand.
*/

#include <iostream>
#include <string>

class FriendClass; // Forward declaration

class ExampleClass {
private:
    std::string name;
    int value;

public:
    ExampleClass(const std::string& name, int value) : name(name), value(value) {}

    // Declare a friend class
    friend class FriendClass;
};

// Friend class definition
class FriendClass {
public:
    void modifyAndDisplay(ExampleClass& obj) {
        obj.value += 10; // Access private member
        std::cout << "Friend Class: Name = " << obj.name << ", Modified Value = " << obj.value << std::endl;
    }
};

int main() {
    ExampleClass example("TestObject", 42);

    // Use the friend class
    FriendClass friendObj;
    friendObj.modifyAndDisplay(example);

    return 0;
}

// Output:
// Friend Class: Name = TestObject, Modified Value = 52