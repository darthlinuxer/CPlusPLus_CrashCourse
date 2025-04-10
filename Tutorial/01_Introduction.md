# Chapter 1: Introduction to C++

## 1.1 Overview of C++
C++ is a powerful, high-performance programming language that has evolved significantly since its creation in the 1980s. It is widely used in systems programming, game development, and performance-critical applications.

### Why Learn C++ as a C# Developer?
- **Performance**: C++ provides fine-grained control over memory and system resources.
- **Portability**: C++ is supported on virtually every platform.
- **Versatility**: It supports multiple paradigms, including procedural, object-oriented, and generic programming.

---

## 1.2 Key Differences Between C++ and C#
| Feature                | C++                                   | C#                                   |
|------------------------|---------------------------------------|--------------------------------------|
| **Memory Management**  | Manual (pointers, `new`, `delete`)    | Automatic (Garbage Collection)       |
| **Compilation**        | Compiled to machine code              | Compiled to Intermediate Language    |
| **Syntax**             | Complex, with manual resource control | Simplified, with built-in safety     |
| **Standard Library**   | STL, Boost, etc.                      | .NET Framework                       |
| **Cross-Platform**     | Requires manual setup                 | Built-in cross-platform support      |

---

## 1.3 Setting Up the Development Environment
### Tools and Compilers
- **Windows**: Visual Studio (with `cl.exe`).
- **Linux**: GCC (`g++`).
- **MacOS**: Not covered in this tutorial.

### Writing and Running a Simple Program
Below is a simple "Hello, World!" program in C++:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

To compile and run this program:

#### On Windows:
1. Save the file as `hello.cpp`.
2. Open the **Developer PowerShell for Visual Studio**.
3. Compile the program:
   - Run: `cl /EHsc /std:c++20 hello.cpp`.
4. Run the program:
   - Execute: `hello.exe`.

#### On Linux:
1. Save the file as `hello.cpp`.
2. Open a terminal.
3. Compile the program:
   - Run: `g++ -std=c++20 hello.cpp -o hello`.
4. Run the program:
   - Execute: `./hello`.

---

### Note on Dependencies
If you do not have Visual Studio or GCC installed, check the `setup_dependencies` file in the root directory of this project for instructions on installing the required tools.

```plaintext
# This file contains instructions for setting up dependencies for this project.
# It includes links to download Visual Studio and GCC.
```

---

## 1.4 Side-by-Side Syntax Comparison
### Variable Declaration
| C++                                   | C#                                   |
|---------------------------------------|--------------------------------------|
| `int x = 10;`                         | `int x = 10;`                        |
| `std::string name = "John";`          | `string name = "John";`              |

### Control Flow
| C++                                   | C#                                   |
|---------------------------------------|--------------------------------------|
| `if (x > 5) { ... }`                  | `if (x > 5) { ... }`                 |
| `switch (x) { case 1: ... }`          | `switch (x) { case 1: ... }`         |

### Functions
| C++                                   | C#                                   |
|---------------------------------------|--------------------------------------|
| `int add(int a, int b) { return a + b; }` | `int Add(int a, int b) { return a + b; }` |

---

## 1.5 Exercises
1. Write a C++ program that prints your name and age.
2. Modify the "Hello, World!" program to print a custom message.
3. Compare the output of a simple `if-else` statement in C++ and C#.

---

## 1.6 Summary
- C++ is a versatile and high-performance language.
- It differs from C# in memory management, compilation, and syntax.
- Setting up a C++ environment is straightforward with tools like Visual Studio.

---

