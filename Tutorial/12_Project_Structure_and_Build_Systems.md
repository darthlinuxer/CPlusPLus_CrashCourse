# Chapter 12: C++ Project Structure and Build Systems

## 12.1 Introduction
A well-structured project and an efficient build system are essential for managing complexity in C++ development. This chapter explores how to organize C++ projects and use `CMake` for build automation.

---

## 12.2 Project Structure
Organizing your project into logical directories improves maintainability and scalability.

### Example: Basic Project Structure
```
MyProject/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── utils.cpp
├── include/
│   ├── utils.h
├── build/
```

- **`src/`**: Contains source files (`.cpp`).
- **`include/`**: Contains header files (`.h` or `.hpp`).
- **`build/`**: Directory for build artifacts (e.g., executables, object files).
- **`CMakeLists.txt`**: Configuration file for `CMake`.

---

## 12.3 Using CMake
CMake is a popular build system generator that simplifies the process of building and managing C++ projects.

### Writing a `CMakeLists.txt` File
```cmake
# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable
add_executable(MyProject src/main.cpp src/utils.cpp)
```

### Building the Project
1. Navigate to the `build/` directory:
   ```bash
   mkdir -p build && cd build
   ```
2. Generate build files:
   ```bash
   cmake ..
   ```
3. Build the project:
   ```bash
   cmake --build .
   ```

---

## 12.4 Best Practices
1. **Separate Headers and Source Files**:
   - Place header files in the `include/` directory and source files in the `src/` directory.

2. **Use Meaningful Names**:
   - Name files and directories descriptively (e.g., `utils.cpp` instead of `file1.cpp`).

3. **Keep Build Artifacts Separate**:
   - Use a dedicated `build/` directory to keep your source tree clean.

4. **Use Version Control**:
   - Exclude the `build/` directory from version control by adding it to `.gitignore`.

5. **Leverage CMake Features**:
   - Use `target_include_directories` and `target_link_libraries` for modular builds.

---

## 12.5 Code Examples
### Example: `main.cpp`
```cpp
// filepath: c:\Users\CCHAVES\dev\CPlusPLus_CrashCourse\MyProject\src\main.cpp
#include <iostream>
#include "utils.h"

int main() {
    std::cout << "Sum: " << add(3, 4) << "\n";
    return 0;
}
```

### Example: `utils.cpp`
```cpp
// filepath: c:\Users\CCHAVES\dev\CPlusPLus_CrashCourse\MyProject\src\utils.cpp
#include "utils.h"

int add(int a, int b) {
    return a + b;
}
```

### Example: `utils.h`
```cpp
// filepath: c:\Users\CCHAVES\dev\CPlusPLus_CrashCourse\MyProject\include\utils.h
#ifndef UTILS_H
#define UTILS_H

int add(int a, int b);

#endif // UTILS_H
```

---

## 12.6 Exercises
1. Create a new project with the structure described above and implement a function to multiply two numbers.
2. Write a `CMakeLists.txt` file to build the project.
3. Use `CMake` to generate build files and compile the project.
4. Refactor an existing project to separate headers and source files into `include/` and `src/` directories.

---

## 12.7 Summary
- Organize your project into logical directories for better maintainability.
- Use `CMake` to simplify the build process and manage dependencies.
- Follow best practices like separating headers and source files and keeping build artifacts out of the source tree.

---
