#include <iostream>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// A simple wrapper to store a function pointer
class FunctionWrapper {
public:
    using FunctionType = int (*)(int, int);

    FunctionWrapper(FunctionType func) : func_(func) {}

    int operator()(int a, int b) const {
        return func_(a, b);
    }

private:
    FunctionType func_;
};

// A simple implementation of partial application
class PartialApplication {
public:
    PartialApplication(int fixedArg, int (*func)(int, int))
        : fixedArg_(fixedArg), func_(func) {}

    int operator()(int otherArg) const {
        return func_(fixedArg_, otherArg);
    }

private:
    int fixedArg_;
    int (*func_)(int, int);
};

int main() {
    // Use FunctionWrapper to store a callable
    FunctionWrapper func(add);

    // Call the function
    std::cout << "Result of add(3, 4): " << func(3, 4) << "\n";

    // Use PartialApplication to create a partially applied function
    PartialApplication addFive(5, add);

    // Call the partially applied function
    std::cout << "Result of addFive(10): " << addFive(10) << "\n";

    return 0;
}

/*
Expected Output:
Result of add(3, 4): 7
Result of addFive(10): 15
*/