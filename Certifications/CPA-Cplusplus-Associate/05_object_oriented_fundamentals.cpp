// Exam block #5: Fundamentals of the object-oriented approach
// class, objects, class components, constructors, referring to objects
// static members, classes and their friends, defining and overloading operators

#include <iostream>

class Counter {
    int value;
    static int count;
public:
    Counter(int v = 0) : value(v) { count++; }
    ~Counter() { count--; }
    int getValue() const { return value; }
    void setValue(int v) { value = v; }
    static int getCount() { return count; }
    // Overload + operator
    Counter operator+(const Counter& other) const {
        return Counter(value + other.value);
    }
    // Friend function
    friend void show(const Counter& c);
};
int Counter::count = 0;

void show(const Counter& c) {
    std::cout << "Counter value: " << c.value << std::endl;
}

int main() {
    Counter c1(5), c2(10);
    Counter c3 = c1 + c2;
    show(c3);
    std::cout << "Active counters: " << Counter::getCount() << std::endl;
    return 0;
}

// Output:
// Counter value: 15
// Active counters: 3
