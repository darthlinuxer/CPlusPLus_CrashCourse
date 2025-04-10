# Chapter 14: C++ Design Patterns

## 14.1 Introduction
Design patterns are reusable solutions to common software design problems. This chapter explores creational, structural, and behavioral patterns in C++.

---

## 14.2 Creational Patterns
Creational patterns deal with object creation mechanisms.

### Singleton Pattern
The Singleton pattern ensures that a class has only one instance and provides a global point of access to it.

#### Example: Singleton
```cpp
#include <iostream>
#include <memory>

class Singleton {
private:
    static std::unique_ptr<Singleton> instance;

    // Private constructor
    Singleton() {
        std::cout << "Singleton instance created\n";
    }

public:
    static Singleton& getInstance() {
        if (!instance) {
            instance = std::make_unique<Singleton>();
        }
        return *instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton\n";
    }
};

std::unique_ptr<Singleton> Singleton::instance = nullptr;

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.showMessage();

    Singleton& s2 = Singleton::getInstance();
    s2.showMessage();

    return 0;
}
```
**Expected Output**:
```
Singleton instance created
Hello from Singleton
Hello from Singleton
```

### Factory Pattern
The Factory pattern provides an interface for creating objects without specifying their concrete classes.

#### Example: Factory
```cpp
#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle\n";
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") {
            return std::make_unique<Circle>();
        } else if (type == "rectangle") {
            return std::make_unique<Rectangle>();
        }
        return nullptr;
    }
};

int main() {
    auto shape1 = ShapeFactory::createShape("circle");
    shape1->draw();

    auto shape2 = ShapeFactory::createShape("rectangle");
    shape2->draw();

    return 0;
}
```
**Expected Output**:
```
Drawing Circle
Drawing Rectangle
```

---

## 14.3 Structural Patterns
Structural patterns deal with object composition and relationships.

### Adapter Pattern
The Adapter pattern allows incompatible interfaces to work together.

#### Example: Adapter
```cpp
#include <iostream>

class OldPrinter {
public:
    void printOld() {
        std::cout << "Printing using OldPrinter\n";
    }
};

class NewPrinter {
public:
    virtual void print() = 0;
};

class PrinterAdapter : public NewPrinter {
private:
    OldPrinter& oldPrinter;

public:
    PrinterAdapter(OldPrinter& printer) : oldPrinter(printer) {}

    void print() override {
        oldPrinter.printOld();
    }
};

int main() {
    OldPrinter oldPrinter;
    PrinterAdapter adapter(oldPrinter);
    adapter.print();

    return 0;
}
```
**Expected Output**:
```
Printing using OldPrinter
```

---

## 14.4 Behavioral Patterns
Behavioral patterns deal with object interaction and responsibility.

### Observer Pattern
The Observer pattern defines a one-to-many dependency between objects.

#### Example: Observer
```cpp
#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notify(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << name << " received: " << message << "\n";
    }
};

int main() {
    Subject subject;

    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.notify("Hello Observers!");

    return 0;
}
```
**Expected Output**:
```
Observer1 received: Hello Observers!
Observer2 received: Hello Observers!
```

---

## 14.5 Code Examples
### Example: Combining Patterns
```cpp
#include <iostream>
#include <memory>
#include <vector>

class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation\n";
    }
};

class Decorator : public Component {
protected:
    std::unique_ptr<Component> component;

public:
    explicit Decorator(std::unique_ptr<Component> comp) : component(std::move(comp)) {}

    void operation() const override {
        component->operation();
    }
};

class ConcreteDecorator : public Decorator {
public:
    explicit ConcreteDecorator(std::unique_ptr<Component> comp) : Decorator(std::move(comp)) {}

    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecorator additional operation\n";
    }
};

int main() {
    auto component = std::make_unique<ConcreteComponent>();
    auto decorated = std::make_unique<ConcreteDecorator>(std::move(component));

    decorated->operation();

    return 0;
}
```
**Expected Output**:
```
ConcreteComponent operation
ConcreteDecorator additional operation
```

---

## 14.6 Exercises
1. Implement a Singleton class for managing application configuration.
2. Create a Factory that generates different types of vehicles (e.g., Car, Bike).
3. Use the Adapter pattern to adapt an existing class to a new interface.
4. Implement the Observer pattern to notify multiple listeners of a stock price change.

---

## 14.7 Summary
- Design patterns provide reusable solutions to common software design problems.
- Creational patterns like Singleton and Factory manage object creation.
- Structural patterns like Adapter simplify object composition.
- Behavioral patterns like Observer manage object interaction and responsibility.

---
