// This file demonstrates the importance of marking destructors as virtual in C++.
// Why this is the right way:
// - Virtual destructors ensure that the correct destructor is called for derived classes, preventing resource leaks.
// - It is essential for polymorphic base classes to avoid undefined behavior.
// How a noob might do it:
// - A noob might omit the virtual keyword, leading to incomplete destruction of derived objects.

#include <iostream>
#include <memory>

// Demonstrating the importance of marking destructors as virtual
class BaseWithNonvirtualDestructor {
public:
    void foo() {
        std::cout << "do foo\n";
    }

    virtual ~BaseWithNonvirtualDestructor() {
        std::cout << "called base destructor\n";
    }
};

class Derived : public BaseWithNonvirtualDestructor {
public:
    ~Derived() override {
        std::cout << "called derived destructor\n";
    }
};

void consumeBase(std::unique_ptr<BaseWithNonvirtualDestructor> p) {
    p->foo();
    // deletes p when done
}

int main() {
    auto derived = std::make_unique<Derived>();
    consumeBase(std::move(derived)); // takes ownership and deletes when done
    return 0;
}

/* Expected Output:
do foo
called derived destructor
called base destructor
*/