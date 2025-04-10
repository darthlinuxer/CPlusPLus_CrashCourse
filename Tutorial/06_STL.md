# Chapter 6: Standard Template Library (STL)

## 6.1 Introduction
The Standard Template Library (STL) is a powerful library in C++ that provides generic classes and functions. It includes containers, iterators, and algorithms, making it easier to work with collections of data.

> **Note**: The STL is available starting from **C++98**, but some features used in this chapter (e.g., range-based for loops, structured bindings, and fold expressions) require **C++11** or later. Ensure your compiler supports the required C++ version.

---

## 6.2 Containers
Containers are data structures that store collections of elements. The STL provides several types of containers, including `vector`, `map`, and `set`.

### Example: `std::vector`
A dynamic array that can grow or shrink in size. Available since **C++98**.
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    numbers.push_back(6); // Add an element
    numbers.pop_back();   // Remove the last element

    for (int num : numbers) {
        std::cout << num << " "; // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### Example: `std::map`
A key-value pair container where keys are unique and sorted. Available since **C++98**. Structured bindings require **C++17**.
```cpp
#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;

    for (const auto& [name, age] : ages) { // Requires C++17
        std::cout << name << ": " << age << "\n";
    }
    return 0;
}
```

### Example: `std::set`
A container that stores unique elements in sorted order. Available since **C++98**.
```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> uniqueNumbers = {3, 1, 4, 1, 5};
    uniqueNumbers.insert(2);

    for (int num : uniqueNumbers) {
        std::cout << num << " "; // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

---

## 6.3 Iterators
Iterators are objects that allow you to traverse elements in a container.

### Example: Using Iterators with `std::vector`
Available since **C++98**.
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### Example: Range-Based For Loop
Available since **C++11**.
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        std::cout << num << " "; // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

---

## 6.4 Algorithms
The STL provides a wide range of algorithms for operations like sorting, searching, and accumulating.

### Example: `std::sort`
Available since **C++98**.
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};
    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " "; // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### Example: `std::find`
Available since **C++98**.
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto it = std::find(numbers.begin(), numbers.end(), 3);

    if (it != numbers.end()) {
        std::cout << "Found: " << *it << "\n"; // Outputs: Found: 3
    } else {
        std::cout << "Not found\n";
    }
    return 0;
}
```

### Example: `std::accumulate`
Available since **C++98**.
```cpp
#include <vector>
#include <numeric>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum: " << sum << "\n"; // Outputs: Sum: 15
    return 0;
}
```

---

## 6.5 Code Examples
### Example: Combining Containers and Algorithms
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};
    std::sort(numbers.begin(), numbers.end()); // Requires C++98

    for (int num : numbers) {
        std::cout << num << " "; // Outputs: 1 2 3 4 5
    }

    auto it = std::find(numbers.begin(), numbers.end(), 3); // Requires C++98
    if (it != numbers.end()) {
        std::cout << "\nFound: " << *it << "\n"; // Outputs: Found: 3
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0); // Requires C++98
    std::cout << "Sum: " << sum << "\n"; // Outputs: Sum: 15

    return 0;
}
```

---

## 6.6 Exercises
1. Create a `std::vector` of integers and sort it in descending order using `std::sort`. (Requires **C++98**)
2. Use a `std::map` to store the names and ages of people. Print the names in alphabetical order. (Requires **C++98**; structured bindings require **C++17**)
3. Write a program that uses `std::set` to store unique words from a sentence. (Requires **C++98**)
4. Use `std::accumulate` to compute the product of all elements in a `std::vector`. (Requires **C++98**)

---

## 6.7 Summary
- The STL provides powerful tools for working with collections of data.
- Containers like `vector`, `map`, and `set` simplify data storage and manipulation.
- Iterators allow traversal of container elements.
- Algorithms like `sort`, `find`, and `accumulate` make common operations easy and efficient.
- Ensure your compiler supports the required C++ version for the features you use.

---
