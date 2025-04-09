#include <iostream>
#include <string>
#include <vector>

// Base class for all animals
class Animal
{
protected:
    std::string name;

public:
    Animal(const std::string &name) : name(name) {}

    virtual void speak() const = 0; // Pure virtual function for speaking

    std::string getName() const
    {
        return name;
    }

    virtual ~Animal() = default; // Virtual destructor for proper cleanup
};

// Interface for animals that can walk
// This is a common pattern in C++ to define interfaces.
// An interface is a class that has only pure virtual functions and no data members.
// It is used to define a contract that derived classes must follow.
class Walkable
{
public:
    virtual void walk() const = 0; // Pure virtual function for walking
    virtual ~Walkable() = default;
};

// Interface for animals that can fly
class Flyable
{
public:
    virtual void fly() const = 0; // Pure virtual function for flying
    virtual ~Flyable() = default;
};

// Dog class: Implements Animal and Walkable
class Dog : public Animal, public Walkable
{
public:
    Dog(const std::string &name) : Animal(name) {}

    void speak() const override
    {
        std::cout << name << " says: Woof!\n";
    }

    void walk() const override
    {
        std::cout << name << " walks on four legs.\n";
    }
};

// Cat class: Implements Animal and Walkable
class Cat : public Animal, public Walkable
{
public:
    Cat(const std::string &name) : Animal(name) {}

    void speak() const override
    {
        std::cout << name << " says: Meow!\n";
    }

    void walk() const override
    {
        std::cout << name << " walks gracefully.\n";
    }
};

// Bird class: Implements Animal and Flyable
class Bird : public Animal, public Flyable
{
public:
    Bird(const std::string &name) : Animal(name) {}

    void speak() const override
    {
        std::cout << name << " says: Tweet!\n";
    }

    void fly() const override
    {
        std::cout << name << " flies in the sky.\n";
    }
};

int main()
{
    Dog dog("Buddy");
    Cat cat("Whiskers");
    Bird bird("Tweety");

    // Polymorphism for speaking
    std::vector<Animal *> animals = {&dog, &cat, &bird};
    for (const auto &animal : animals)
    {
        animal->speak();
    }

    // Polymorphism for walking
    std::vector<Walkable *> walkables = {&dog, &cat};
    for (const auto &walkable : walkables)
    {
        walkable->walk();
    }

    // Polymorphism for flying
    std::vector<Flyable *> flyables = {&bird};
    for (const auto &flyable : flyables)
    {
        flyable->fly();
    }

    return 0;
}

/*
Buddy says: Woof!
Whiskers says: Meow!
Tweety says: Tweet!
Buddy walks on four legs.
Whiskers walks gracefully.
Tweety flies in the sky.
*/