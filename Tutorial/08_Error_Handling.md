# Chapter 8: Error Handling in C++

## 8.1 Introduction
Error handling in C++ is primarily done using exceptions. Exceptions provide a way to handle runtime errors gracefully without crashing the program. This chapter explores how to use exceptions, create custom exception classes, and follow best practices for error handling.

> **Note**: Exception handling has been part of C++ since **C++98**. Ensure your compiler supports exceptions.

---

## 8.2 Exceptions
Exceptions are used to signal and handle errors during program execution.

### Example: Throwing and Catching Exceptions
Available since **C++98**.
```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        std::cout << "Result: " << divide(10, 2) << "\n"; // Outputs: Result: 5
        std::cout << "Result: " << divide(10, 0) << "\n"; // Throws an exception
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n"; // Outputs: Error: Division by zero
    }
    return 0;
}
```
**Expected Output**:
```
Result: 5
Error: Division by zero
```

---

## 8.3 Custom Exceptions
You can create custom exception classes to represent specific error types.

### Example: Custom Exception Class
Available since **C++98**.
```cpp
#include <iostream>
#include <stdexcept>

class InvalidInputException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidInputException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

void validateInput(int value) {
    if (value < 0) {
        throw InvalidInputException("Negative value is not allowed");
    }
}

int main() {
    try {
        validateInput(10); // Valid input
        validateInput(-5); // Throws an exception
    } catch (const InvalidInputException& e) {
        std::cerr << "Error: " << e.what() << "\n"; // Outputs: Error: Negative value is not allowed
    }
    return 0;
}
```
**Expected Output**:
```
Error: Negative value is not allowed
```

---

## 8.4 Best Practices
1. **Use Exceptions for Exceptional Situations**:
   - Avoid using exceptions for normal control flow.
   - Use exceptions only for unexpected errors.

2. **Catch Exceptions by Reference**:
   - Always catch exceptions by reference to avoid slicing.
   ```cpp
   try {
       throw std::runtime_error("Error");
   } catch (const std::exception& e) {
       std::cerr << e.what() << "\n";
   }
   ```

3. **Use `noexcept` for Non-Throwing Functions**:
   - Mark functions that do not throw exceptions with `noexcept` for better performance.
   ```cpp
   void safeFunction() noexcept {
       // This function will not throw exceptions
   }
   ```

4. **Clean Up Resources**:
   - Use RAII (Resource Acquisition Is Initialization) to ensure resources are released properly.
   ```cpp
   class Resource {
   public:
       Resource() { std::cout << "Resource acquired\n"; }
       ~Resource() { std::cout << "Resource released\n"; }
   };

   void process() {
       Resource res;
       throw std::runtime_error("Error occurred");
   }
   ```

---

## 8.5 Code Examples
### Example: Handling Multiple Exceptions
```cpp
#include <iostream>
#include <stdexcept>

void process(int value) {
    if (value < 0) {
        throw std::invalid_argument("Negative value");
    } else if (value == 0) {
        throw std::runtime_error("Zero value");
    }
}

int main() {
    try {
        process(-1); // Throws an exception
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << "\n";
    }
    return 0;
}
```
**Expected Output**:
```
Invalid argument: Negative value
```

---

## 8.6 Exercises
1. Write a function `safeDivide` that divides two numbers and throws an exception if the denominator is zero.
2. Create a custom exception class `OutOfRangeException` and use it to handle invalid array indices.
3. Write a program that demonstrates the use of `noexcept` in a function.
4. Implement a program that uses RAII to manage a resource and ensures proper cleanup even when an exception is thrown.

---

## 8.7 Summary
- Exceptions provide a way to handle runtime errors gracefully.
- Use custom exception classes to represent specific error types.
- Follow best practices like catching exceptions by reference and using `noexcept` for non-throwing functions.
- Proper error handling ensures robust and maintainable code.

---
