# Chapter 5: Templates

## 5.1 Introduction
Templates in C++ allow you to write generic and reusable code. They enable functions and classes to operate with different data types without rewriting the code for each type.

---

## 5.2 Function Templates
Function templates define a blueprint for creating functions that work with any data type.

### Example: Function Template
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Sum of integers: " << add(3, 4) << "\n"; // Outputs: 7
    std::cout << "Sum of doubles: " << add(3.5, 4.2) << "\n"; // Outputs: 7.7
    return 0;
}
```

---

## 5.3 Class Templates
Class templates define a blueprint for creating classes that work with any data type.

### Example: Class Template
```cpp
template <typename T>
class Pair {
private:
    T first, second;

public:
    Pair(T first, T second) : first(first), second(second) {}

    void display() const {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};

int main() {
    Pair<int> intPair(1, 2);
    intPair.display(); // Outputs: (1, 2)

    Pair<std::string> stringPair("Hello", "World");
    stringPair.display(); // Outputs: (Hello, World)
    return 0;
}
```

---

## 5.4 Variadic Templates
Variadic templates allow you to define templates that accept a variable number of arguments.

### Fold Expressions
A fold expression is a concise way to apply an operation to all arguments in a parameter pack. It was introduced in C++17 and simplifies working with variadic templates.

#### Syntax
```cpp
(expression op ...)  // Unary right fold
(... op expression)  // Unary left fold
(expression op ... op expression)  // Binary fold
```

#### Example: Summing Arguments
```cpp
template <typename... Args>
auto sumAll(Args... args) {
    return (... + args); // Adds all arguments
}

int main() {
    std::cout << "Sum: " << sumAll(1, 2, 3, 4) << "\n"; // Outputs: 10
    return 0;
}
```

#### More Examples of Fold Expressions

##### Unary Right Fold
A unary right fold applies the operation from left to right, starting with the first argument.

```cpp
template <typename... Args>
auto multiplyAll(Args... args) {
    return (args * ...); // Multiplies all arguments
}

int main() {
    std::cout << "Product: " << multiplyAll(1, 2, 3, 4) << "\n"; // Outputs: 24
    return 0;
}
```

##### Unary Left Fold
A unary left fold applies the operation from right to left, starting with the last argument.

```cpp
template <typename... Args>
auto subtractAll(Args... args) {
    return (... - args); // Subtracts all arguments from left to right
}

int main() {
    std::cout << "Result: " << subtractAll(10, 3, 2); // Outputs: 5 (10 - 3 - 2)
    return 0;
}
```

##### Binary Fold
A binary fold applies an operation between two expressions, combining the results.

```cpp
template <typename... Args>
auto combineAll(Args... args) {
    return (args + ... + 0); // Adds all arguments and starts with 0
}

int main() {
    std::cout << "Sum with initial value: " << combineAll(1, 2, 3, 4) << "\n"; // Outputs: 10
    return 0;
}
```

---

## 5.5 Template Specialization
Template specialization allows you to customize the behavior of a template for specific data types.

### Example: Full Specialization
```cpp
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic: " << value << "\n";
    }
};

// Specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "String: " << value << "\n";
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42); // Outputs: Generic: 42

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello"); // Outputs: String: Hello
    return 0;
}
```

---

## 5.6 Code Examples
### Example: Function Template
```cpp
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << "Product of integers: " << multiply(3, 4) << "\n"; // Outputs: 12
    std::cout << "Product of doubles: " << multiply(2.5, 4.0) << "\n"; // Outputs: 10
    return 0;
}
```

### Example: Class Template
```cpp
template <typename T1, typename T2>
class KeyValuePair {
private:
    T1 key;
    T2 value;

public:
    KeyValuePair(T1 key, T2 value) : key(key), value(value) {}

    void display() const {
        std::cout << "Key: " << key << ", Value: " << value << "\n";
    }
};

int main() {
    KeyValuePair<int, std::string> pair(1, "One");
    pair.display(); // Outputs: Key: 1, Value: One
    return 0;
}
```

---

## 5.7 Exercises
1. Write a function template `maxValue` that returns the maximum of two values.
2. Create a class template `Stack` that implements a stack for any data type.
3. Use variadic templates to write a function `sumAll` that computes the sum of all its arguments.
4. Specialize a template class `Printer` for `std::vector<int>` to print all elements of the vector.

---

## 5.8 Summary
- Templates enable generic programming in C++.
- Function templates allow you to write reusable functions for any data type.
- Class templates define generic classes that work with multiple data types.
- Variadic templates handle a variable number of arguments.
- Template specialization customizes templates for specific types.

---
