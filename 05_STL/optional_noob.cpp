#include <iostream>

class NoobOptional {
private:
    bool hasValue;
    int value;

public:
    NoobOptional() : hasValue(false), value(0) {}

    NoobOptional(int val) : hasValue(true), value(val) {}

    bool has_value() const {
        return hasValue;
    }

    int get_value() const {
        return value;
    }
};

NoobOptional findValue(bool condition) {
    if (condition) {
        return NoobOptional(42); // Return a value if the condition is true.
    }
    return NoobOptional(); // Return no value.
}

int main() {
    NoobOptional result = findValue(true);
    if (result.has_value()) {
        std::cout << "Found value: " << result.get_value() << "\n";
    } else {
        std::cout << "No value found.\n";
    }

    return 0;
}

/*
Expected Output:
Found value: 42
*/