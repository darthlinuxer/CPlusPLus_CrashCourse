# Chapter 10: C++ Best Practices

## 10.1 Introduction
C++ is a powerful language, but its complexity can lead to subtle bugs and maintenance challenges. Following best practices ensures that your code is clean, efficient, and maintainable.

---

## 10.2 Code Readability
Readable code is easier to understand, debug, and maintain.

### Use Meaningful Variable Names
```cpp
// Bad
int x = 10;

// Good
int userAge = 10;
```

### Follow Consistent Formatting
```cpp
// Bad
if(x>0){std::cout<<"Positive";}

// Good
if (x > 0) {
    std::cout << "Positive";
}
```

### Comment Your Code
```cpp
// Calculate the area of a rectangle
int area = width * height;
```

---

## 10.3 Memory Management
Proper memory management prevents resource leaks and undefined behavior.

### Use RAII (Resource Acquisition Is Initialization)
RAII ensures that resources are released when objects go out of scope.
```cpp
#include <iostream>
#include <fstream>

void writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename); // RAII ensures the file is closed
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }
    file << content;
}
```

### Prefer Smart Pointers Over Raw Pointers
Smart pointers automatically manage memory and prevent leaks.
```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << "Value: " << *ptr << "\n"; // Outputs: Value: 42
    return 0;
}
```

---

## 10.4 Avoiding Common Pitfalls
Avoiding common mistakes ensures robust and predictable code.

### Initialize Variables
Uninitialized variables can lead to undefined behavior.
```cpp
// Bad
int x; // Uninitialized
std::cout << x; // Undefined behavior

// Good
int x = 0; // Initialized
std::cout << x; // Outputs: 0
```

### Avoid Dangling Pointers
Dangling pointers point to memory that has been deallocated.
```cpp
// Bad
int* ptr = new int(10);
delete ptr;
// ptr is now dangling

// Good
std::unique_ptr<int> ptr = std::make_unique<int>(10);
// Memory is automatically managed
```

### Use `nullptr` Instead of `NULL`
`nullptr` is type-safe and introduced in **C++11**.
```cpp
int* ptr = nullptr; // Safe initialization
```

---

## 10.5 Code Examples
### Example: Using RAII for Resource Management
```cpp
#include <iostream>
#include <fstream>

void readFile(const std::string& filename) {
    std::ifstream file(filename); // RAII ensures the file is closed
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}

int main() {
    try {
        readFile("example.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
```

### Example: Avoiding Resource Leaks with Smart Pointers
```cpp
#include <memory>
#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
};

int main() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    // Resource is automatically released when res goes out of scope
    return 0;
}
```
**Expected Output**:
```
Resource acquired
Resource released
```

---

## 10.6 Exercises
1. Refactor a program that uses raw pointers to use smart pointers instead. (Requires **C++11**)
2. Write a program that uses RAII to manage a file resource and ensures it is closed even if an exception is thrown.
3. Identify and fix uninitialized variables in a given code snippet.
4. Write a program that demonstrates the use of `nullptr` for safe pointer initialization.

---

## 10.7 Summary
- Follow consistent formatting and use meaningful variable names for readability.
- Use RAII and smart pointers to manage resources safely.
- Avoid common pitfalls like uninitialized variables and dangling pointers.
- Adopting best practices ensures robust, maintainable, and efficient C++ code.

---
