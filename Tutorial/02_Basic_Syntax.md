# Chapter 2: Basic Syntax

## 2.1 Introduction
C++ syntax is similar to C# in many ways but includes additional features for low-level programming. This chapter introduces the basic syntax of C++, including variable declarations, control flow, and functions.

---

## 2.2 Variable Declarations and Data Types
C++ supports a wide range of data types, including primitive types and fixed-width integers.

### Primitive Types
```cpp
int age = 25;
float height = 5.9f;
char grade = 'A';
bool isStudent = true;
```

### Fixed-Width Integer Types
C++ provides fixed-width integer types for precise control over memory usage:
```cpp
#include <cstdint>

std::int8_t smallNumber = 127;
std::uint64_t largeNumber = 18446744073709551615ULL;
```

---

## 2.3 Control Flow
C++ supports common control flow constructs like `if-else`, `switch`, and loops.

### If-Else Statement
```cpp
int number = 10;
if (number > 5) {
    std::cout << "Number is greater than 5.\n";
} else {
    std::cout << "Number is 5 or less.\n";
}
```

### Switch Statement
```cpp
switch (number) {
    case 10:
        std::cout << "Number is exactly 10.\n";
        break;
    case 5:
        std::cout << "Number is exactly 5.\n";
        break;
    default:
        std::cout << "Number is neither 5 nor 10.\n";
        break;
}
```

### Loops
#### For Loop
```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << "Iteration: " << i << "\n";
}
```

#### While Loop
```cpp
int count = 0;
while (count < 3) {
    std::cout << "Count: " << count << "\n";
    ++count;
}
```

#### Do-While Loop
```cpp
int count = 0;
do {
    std::cout << "Count: " << count << "\n";
    ++count;
} while (count < 3);
```

---

## 2.4 Functions
C++ functions are similar to C# methods but offer additional features like default arguments and overloading.

### Function Declaration
```cpp
int add(int a, int b) {
    return a + b;
}
```

### Default Arguments
```cpp
int multiply(int a, int b = 2) {
    return a * b;
}
```

### Function Overloading
```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
```

---

## 2.5 Compile-Time Evaluation
C++ allows computations to be performed at compile time using `constexpr`.

### Example
```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(5); // Computed at compile time
    std::cout << "Square of 5: " << result << "\n";
    return 0;
}
```

---

## 2.6 Exercises
1. Declare variables of different types (e.g., `int`, `float`, `bool`) and print their values.
2. Write a program that uses a `switch` statement to print the name of a day based on an integer input.
3. Create a function with default arguments and call it with and without the default values.
4. Use `constexpr` to compute the factorial of a number at compile time.

---

## 2.7 Summary
- C++ syntax includes variable declarations, control flow constructs, and functions.
- `constexpr` enables compile-time computations for better performance.
- Understanding these basics is essential for writing efficient C++ programs.

---
