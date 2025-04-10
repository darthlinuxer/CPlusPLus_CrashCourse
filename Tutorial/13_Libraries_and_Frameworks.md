# Chapter 13: C++ Libraries and Frameworks

## 13.1 Introduction
Libraries and frameworks extend the functionality of C++ and simplify development. This chapter explores the C++ Standard Library and popular third-party libraries like Boost, Qt, and Eigen.

---

## 13.2 Standard Libraries
The C++ Standard Library provides a wide range of functionality, including containers, algorithms, and utilities.

### Commonly Used Libraries
1. **`<vector>`**: Dynamic arrays.
2. **`<map>`**: Key-value pairs.
3. **`<algorithm>`**: Sorting, searching, and other algorithms.
4. **`<thread>`**: Multithreading support.
5. **`<filesystem>`**: File and directory manipulation (introduced in **C++17**).

### Example: Using `<filesystem>`
Available since **C++17**.
```cpp
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::create_directory("example_dir");
    std::cout << "Directory created: example_dir\n";
    return 0;
}
```
**Expected Output**:
```
Directory created: example_dir
```

---

## 13.3 Third-Party Libraries
Third-party libraries provide additional functionality not included in the C++ Standard Library.

### Boost
Boost is a collection of high-quality libraries that extend the functionality of C++.

#### Example: Using Boost Filesystem
```cpp
#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::create_directory("boost_dir");
    std::cout << "Directory created: boost_dir\n";
    return 0;
}
```

### Qt
Qt is a framework for building cross-platform GUI applications.

#### Example: Simple Qt Application
```cpp
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel label("Hello, Qt!");
    label.show();
    return app.exec();
}
```

### Eigen
Eigen is a library for linear algebra and matrix computations.

#### Example: Matrix Multiplication with Eigen
```cpp
#include <Eigen/Dense>
#include <iostream>

int main() {
    Eigen::Matrix2d mat1;
    mat1 << 1, 2,
            3, 4;

    Eigen::Matrix2d mat2;
    mat2 << 5, 6,
            7, 8;

    Eigen::Matrix2d result = mat1 * mat2;
    std::cout << "Result:\n" << result << "\n";
    return 0;
}
```
**Expected Output**:
```
Result:
19 22
43 50
```

---

## 13.4 Using Libraries with CMake
CMake simplifies the process of integrating libraries into your project.

### Example: Adding Boost to a Project
```cmake
# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyBoostProject)

# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem)

# Include directories
include_directories(${Boost_INCLUDE_DIRS})

# Add executable
add_executable(MyBoostProject src/main.cpp)

# Link Boost libraries
target_link_libraries(MyBoostProject ${Boost_LIBRARIES})
```

---

## 13.5 Code Examples
### Example: Combining Standard and Third-Party Libraries
```cpp
#include <iostream>
#include <filesystem>
#include <boost/filesystem.hpp>

int main() {
    std::filesystem::create_directory("std_dir");
    boost::filesystem::create_directory("boost_dir");

    std::cout << "Directories created: std_dir, boost_dir\n";
    return 0;
}
```
**Expected Output**:
```
Directories created: std_dir, boost_dir
```

---

## 13.6 Exercises
1. Write a program that uses `<filesystem>` to list all files in a directory. (Requires **C++17**)
2. Use Boost to create and delete a directory.
3. Create a simple Qt application that displays a button and a label.
4. Perform matrix addition and multiplication using Eigen.

---

## 13.7 Summary
- The C++ Standard Library provides essential functionality for containers, algorithms, and utilities.
- Third-party libraries like Boost, Qt, and Eigen extend the capabilities of C++.
- Use `CMake` to integrate libraries into your projects efficiently.

---
