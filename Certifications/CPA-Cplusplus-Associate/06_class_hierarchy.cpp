// Exam block #6: Class hierarchy
// base class, superclass, subclass, inheritance: how it works
// types of inheritance, inheriting different class components, multiple inheritance

#include <iostream>

class Animal {
public:
    void speak() const { std::cout << "Animal sound" << std::endl; }
};

class Dog : public Animal {
public:
    void speak() const { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
public:
    void speak() const { std::cout << "Meow!" << std::endl; }
};

class Chimera : public Dog, public Cat {
    // Multiple inheritance
};

int main() {
    Dog d;
    d.speak();
    Cat c;
    c.speak();
    Chimera ch;
    // ch.speak(); // Ambiguous, would need to specify which base
    ch.Dog::speak();
    ch.Cat::speak();
    return 0;
}

// Output:
// Woof!
// Meow!
// Woof!
// Meow!
