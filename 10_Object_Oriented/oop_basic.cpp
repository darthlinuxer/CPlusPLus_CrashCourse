#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}
    virtual void speak() const = 0; // Pure virtual function.
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}
    void speak() const override {
        std::cout << name << " says: Woof!\n";
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    void speak() const override {
        std::cout << name << " says: Meow!\n";
    }
};

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.speak();
    cat.speak();

    return 0;
}