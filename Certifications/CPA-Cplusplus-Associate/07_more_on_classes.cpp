// Exam block #7: More on classes
// polymorphism: the notion and the purpose
// virtual methods: declaration and usage
// inheriting virtual methods, abstraction and abstract classes

#include <iostream>

class Shape {
public:
    virtual void draw() const = 0; // Abstract method
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

void render(const Shape& s) {
    s.draw();
}

int main() {
    Circle c;
    Square s;
    render(c);
    render(s);
    return 0;
}

// Output:
// Drawing Circle
// Drawing Square
