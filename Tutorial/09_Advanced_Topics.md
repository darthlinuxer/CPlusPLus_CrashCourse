# Chapter 9: Advanced Topics in C++

## 9.1 Introduction
This chapter explores advanced topics in C++ that enable developers to write efficient and flexible code. Topics include move semantics, perfect forwarding, and type traits.

> **Note**: These features require **C++11** or later. Ensure your compiler supports at least **C++11**.

---

## 9.2 Move Semantics
Move semantics allow you to transfer resources from one object to another, avoiding unnecessary copies.

### Example: Using `std::move`
Available since **C++11**.
```cpp
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = std::move(vec1); // Transfers ownership

    std::cout << "vec1 size: " << vec1.size() << "\n"; // Outputs: vec1 size: 0
    std::cout << "vec2 size: " << vec2.size() << "\n"; // Outputs: vec2 size: 3

    return 0;
}
```
**Expected Output**:
```
vec1 size: 0
vec2 size: 3
```

---

## 9.3 Perfect Forwarding
Perfect forwarding allows you to forward arguments to another function while preserving their value category (lvalue or rvalue).

### Example: Perfect Forwarding with Templates
Available since **C++11**.
```cpp
#include <iostream>
#include <utility>

void process(int& x) {
    std::cout << "Lvalue: " << x << "\n";
}

void process(int&& x) {
    std::cout << "Rvalue: " << x << "\n";
}

template <typename T>
void forwarder(T&& arg) {
    process(std::forward<T>(arg)); // Perfectly forwards the argument
}

int main() {
    int a = 10;
    forwarder(a);        // Calls process(int&)
    forwarder(20);       // Calls process(int&&)

    return 0;
}
```
**Expected Output**:
```
Lvalue: 10
Rvalue: 20
```

---

## 9.4 Type Traits
Type traits provide compile-time information about types and enable conditional compilation.

### Example: Using `std::enable_if`
Available since **C++11**.
```cpp
#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printIfIntegral(T value) {
    std::cout << "Integral value: " << value << "\n";
}

int main() {
    printIfIntegral(42);       // Outputs: Integral value: 42
    // printIfIntegral(3.14);  // Compilation error: not an integral type

    return 0;
}
```
**Expected Output**:
```
Integral value: 42
```

---

## 9.5 Code Examples
### Example: Combining Move Semantics and Type Traits
```cpp
#include <iostream>
#include <vector>
#include <type_traits>
#include <utility>

template <typename T>
void moveIfPossible(T&& value) {
    if constexpr (std::is_move_constructible<T>::value) {
        T movedValue = std::move(value);
        std::cout << "Moved value successfully\n";
    } else {
        std::cout << "Move not possible\n";
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    moveIfPossible(vec); // Outputs: Moved value successfully

    return 0;
}
```
**Expected Output**:
```
Moved value successfully
```

---

## 9.6 Exercises
1. Write a program that demonstrates the use of `std::move` to transfer ownership of a dynamically allocated resource. (Requires **C++11**)
2. Implement a template function that uses perfect forwarding to call different overloads of a function. (Requires **C++11**)
3. Use `std::enable_if` to create a function that only accepts floating-point types. (Requires **C++11**)
4. Write a program that uses `if constexpr` to check if a type is default-constructible and prints a message accordingly. (Requires **C++17**)

---

## 9.7 Summary
- Move semantics enable efficient resource transfers using `std::move`.
- Perfect forwarding preserves the value category of arguments.
- Type traits like `std::enable_if` provide compile-time type information.
- Advanced C++ features improve code efficiency and flexibility.

---
