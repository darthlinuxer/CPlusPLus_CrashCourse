# Chapter 4: Object-Oriented Programming

## 4.1 Introduction
Object-oriented programming (OOP) is a paradigm that organizes code into objects, which combine data and behavior. C++ supports OOP with features like classes, inheritance, and polymorphism.

---

## 4.2 Classes and Objects
A class is a blueprint for creating objects. It defines data members (attributes) and member functions (methods).

### Defining a Class
```cpp
class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Method
    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};
```

### Creating an Object
```cpp
Person person("Alice", 30);
person.introduce();
```

---

## 4.3 Inheritance
Inheritance allows a class to derive properties and behavior from another class.

### Single Inheritance
```cpp
class Employee : public Person {
private:
    std::string position;

public:
    Employee(const std::string& name, int age, const std::string& position)
        : Person(name, age), position(position) {}

    void work() const {
        std::cout << "Working as a " << position << ".\n";
    }
};
```

### Multiple Inheritance
```cpp
class Manager : public Employee, public Leader {
    // Combines behavior from Employee and Leader
};
```

---

## 4.4 Polymorphism
Polymorphism allows objects to be treated as instances of their base class, enabling dynamic behavior.

### Virtual Functions
```cpp
class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks.\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!\n";
    }
};
```

### Using Polymorphism
```cpp
Animal* animal = new Dog();
animal->speak(); // Outputs: Woof!
delete animal;
```

---

## 4.5 Encapsulation
Encapsulation restricts access to an object's internal state using access specifiers.

### Access Specifiers
- **`private`**: Accessible only within the class.
- **`protected`**: Accessible within the class and derived classes.
- **`public`**: Accessible from anywhere.

### Example
```cpp
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};
```

---

## 4.6 Abstract Classes and Interfaces
An abstract class contains at least one pure virtual function and cannot be instantiated. Abstract classes are often used to define interfaces in C++.

### Interfaces in C++
In C++, an interface is typically implemented as a class with only pure virtual functions and no data members. It defines a contract that derived classes must follow.

### Example: Interface
```cpp
class Drawable {
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Drawable() = default; // Virtual destructor for proper cleanup
};

class Circle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a circle.\n";
    }
};

class Rectangle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle.\n";
    }
};
```

### Using an Interface
```cpp
std::vector<std::unique_ptr<Drawable>> shapes;
shapes.push_back(std::make_unique<Circle>());
shapes.push_back(std::make_unique<Rectangle>());

for (const auto& shape : shapes) {
    shape->draw(); // Calls the appropriate draw method
}
```

---

## 4.7 Code Examples
### Example: Polymorphism
```cpp
Animal* dog = new Dog();
dog->speak(); // Outputs: Woof!
delete dog;
```

### Example: Abstract Classes
```cpp
Shape* shape = new Circle();
shape->draw(); // Outputs: Drawing a circle.
delete shape;
```

---

## 4.8 Exercises
1. Create a `Car` class with attributes like `brand` and `year`. Add methods to display its details.
2. Implement a `Rectangle` and `Circle` class that inherit from a `Shape` abstract class. Add a `draw` method to each.
3. Use polymorphism to store different shapes in a collection and call their `draw` methods.
4. Create a `BankAccount` class with methods for deposit and withdrawal. Use encapsulation to protect the balance.

---

## 4.9 Summary
- Classes and objects are the foundation of OOP in C++.
- Inheritance allows code reuse and hierarchical relationships.
- Polymorphism enables dynamic behavior through virtual functions.
- Encapsulation protects an object's internal state.
- Abstract classes define interfaces for derived classes.

---

## 4.10 Constructors and Destructors
Constructors and destructors are special member functions that are automatically called when an object is created or destroyed.

### Default Constructor
A default constructor is a constructor with no parameters. It initializes an object with default values.

```cpp
class Person {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Person() : name("Unknown"), age(0) {}

    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Person person; // Created on the stack
    person.introduce(); // Outputs: Hi, I'm Unknown and I'm 0 years old.
    // The `person` object goes out of scope when the main function ends.
}
```

### Parameterized Constructor
A constructor that takes arguments to initialize an object.

```cpp
int main() {
    Person* person = new Person("Alice", 30); // Created on the heap
    person->introduce(); // Outputs: Hi, I'm Alice and I'm 30 years old.
    delete person; // Explicitly deallocate memory to avoid memory leaks
    // The `person` pointer goes out of scope when the main function ends, but the memory must be freed manually.
}
```

### Destructor
A destructor is called automatically when an object goes out of scope or is deleted. It is used to release resources.

```cpp
class Resource {
public:
    ~Resource() {
        std::cout << "Resource destroyed.\n";
    }
};

int main() {
    {
        Resource res; // Created on the stack
        // The `res` object is destroyed automatically when it goes out of scope at the end of this block.
    }
    std::cout << "End of block.\n";
}
```

---

## 4.11 Copy and Move Semantics
C++ provides mechanisms for copying and moving objects, which are essential for managing resources efficiently.

### Copy Constructor
A copy constructor creates a new object as a copy of an existing object.

```cpp
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called.\n";
    }
};

int main() {
    Person person1("Alice", 30); // Created on the stack
    Person person2 = person1; // Copy constructor is called
    // Both `person1` and `person2` go out of scope when the main function ends.
}
```

### Move Constructor
A move constructor transfers resources from one object to another, avoiding deep copies.

```cpp
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Move constructor
    Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
        other.age = 0; // Reset the moved-from object
        std::cout << "Move constructor called.\n";
    }
};

int main() {
    Person person1("Alice", 30); // Created on the stack
    Person person2 = std::move(person1); // Move constructor is called
    // `person1` is in a valid but unspecified state.
    // Both `person1` and `person2` go out of scope when the main function ends.
}
```

---

## 4.12 Operator Overloading
Operator overloading allows you to redefine the behavior of operators for user-defined types.

### Overloading the Assignment Operator
```cpp
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

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
            other.age = 0; // Reset the moved-from object
        }
        return *this;
    }
};

int main() {
    Person person1("Alice", 30); // Created on the stack
    Person person2("Bob", 25); // Created on the stack
    person2 = person1; // Copy assignment operator is called
    person2 = std::move(person1); // Move assignment operator is called
    // Both `person1` and `person2` go out of scope when the main function ends.
}
```

### Overloading Arithmetic Operators
```cpp
class Vector {
private:
    int x, y;

public:
    Vector(int x, int y) : x(x), y(y) {}

    // Overload + operator
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

Vector v1(1, 2);
Vector v2(3, 4);
Vector v3 = v1 + v2; // + operator is overloaded
v3.display(); // Outputs: (4, 6)
```

---

## 4.13 Exercises
1. Add a default constructor to the `Car` class and initialize its attributes with default values.
2. Implement a copy constructor for the `Rectangle` class to copy its dimensions.
3. Add a move constructor to the `Circle` class to transfer ownership of its radius.
4. Overload the `+` operator for the `BankAccount` class to combine balances.
5. Overload the `==` operator for the `Person` class to compare names and ages.

---

## 4.14 Summary
- Constructors and destructors manage object initialization and cleanup.
- Copy and move semantics are essential for efficient resource management.
- Operator overloading allows custom behavior for operators in user-defined types.

---

## 4.15 Virtual Destructors
A virtual destructor ensures that the destructor of the derived class is called when an object is deleted through a base class pointer. This is crucial for proper cleanup in polymorphic classes.

### Why Use Virtual Destructors?
When a base class pointer points to a derived class object, deleting the object without a virtual destructor can lead to undefined behavior or resource leaks.

### Example Without Virtual Destructor
```cpp
class Base {
public:
    ~Base() {
        std::cout << "Base destructor called.\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called.\n";
    }
};

Base* obj = new Derived();
delete obj; // Only Base destructor is called, leading to a potential resource leak
```

### Example With Virtual Destructor
```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called.\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called.\n";
    }
};

int main() {
    Base* obj = new Derived(); // Base pointer to a Derived object (created on the heap)
    delete obj; // Both Derived and Base destructors are called
    // The `obj` pointer goes out of scope when the main function ends, but the memory must be freed manually.
}
```

### When to Use Virtual Destructors
- Use virtual destructors in base classes if the class is intended to be used polymorphically.
- Avoid virtual destructors in non-polymorphic classes to minimize overhead.

---

## 4.16 Exercises
1. Create an interface `Drawable` with a pure virtual function `draw`. Implement `Circle` and `Rectangle` classes that inherit from it.
2. Use a vector of `std::unique_ptr<Drawable>` to store and draw multiple shapes.
3. Modify the `BankAccount` class to use a virtual destructor and demonstrate polymorphic behavior with derived classes like `SavingsAccount` and `CheckingAccount`.
4. Explain the difference between a pure virtual function and a virtual destructor in your own words.
5. Identify whether variables in the examples are created on the stack or heap and explain when they go out of scope.

---

## 4.17 Summary
- Abstract classes and interfaces define contracts for derived classes.
- Virtual destructors ensure proper cleanup in polymorphic hierarchies.
- Use virtual destructors in base classes when polymorphism is involved.
- Understand whether variables are created on the stack or heap and when they go out of scope.

---
