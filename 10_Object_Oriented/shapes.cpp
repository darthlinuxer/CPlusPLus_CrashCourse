#include <iostream>
#include <string>
#include <vector>

// Base class: Shape
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string &color) : color(color) {}

    virtual void draw() const = 0; // Pure virtual function

    virtual ~Shape() = default;
};

// Derived class: Circle
class Circle : public Shape {
    double radius;

public:
    Circle(const std::string &color, double radius) : Shape(color), radius(radius) {}

    void draw() const override {
        std::cout << "Drawing a " << color << " circle with radius " << radius << ".\n";
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(const std::string &color, double width, double height)
        : Shape(color), width(width), height(height) {}

    void draw() const override {
        std::cout << "Drawing a " << color << " rectangle with width " << width
                  << " and height " << height << ".\n";
    }
};

// Demonstrating polymorphism
int main() {
    std::vector<Shape *> shapes;

    shapes.push_back(new Circle("red", 5.0));
    shapes.push_back(new Rectangle("blue", 4.0, 6.0));

    for (const auto &shape : shapes) {
        shape->draw();
    }

    // Clean up dynamically allocated memory
    for (auto &shape : shapes) {
        delete shape;
    }

    return 0;
}

/*
Output:
Drawing a red circle with radius 5.
Drawing a blue rectangle with width 4 and height 6.
*/