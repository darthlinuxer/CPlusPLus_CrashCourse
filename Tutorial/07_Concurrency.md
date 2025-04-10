# Chapter 7: Concurrency in C++

## 7.1 Introduction
Concurrency in C++ allows you to perform multiple tasks simultaneously, improving performance and responsiveness. C++ provides a rich set of tools for concurrency, including threads, synchronization primitives, and asynchronous programming.

> **Note**: Concurrency features in C++ are available starting from **C++11**. Ensure your compiler supports at least **C++11**.

---

## 7.2 Threads
Threads allow you to execute multiple tasks concurrently.

### Example: Creating Threads
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>

void printMessage(const std::string& message) {
    std::cout << message << "\n";
}

int main() {
    std::thread t1(printMessage, "Hello from thread 1");
    std::thread t2(printMessage, "Hello from thread 2");

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    return 0;
}
```
**Expected Output** (order may vary due to concurrency):
```
Hello from thread 1
Hello from thread 2
```

### Example: Lambda Functions with Threads
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>

int main() {
    std::thread t([]() {
        std::cout << "Hello from a lambda thread\n";
    });

    t.join(); // Wait for the thread to finish
    return 0;
}
```
**Expected Output**:
```
Hello from a lambda thread
```

---

## 7.3 Synchronization
Synchronization is essential to avoid race conditions when multiple threads access shared resources.

### Example: Using `std::mutex`
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printSafe(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx); // Automatically locks and unlocks
    std::cout << message << "\n";
}

int main() {
    std::thread t1(printSafe, "Thread 1: Safe message");
    std::thread t2(printSafe, "Thread 2: Safe message");

    t1.join();
    t2.join();

    return 0;
}
```
**Expected Output** (order may vary due to concurrency):
```
Thread 1: Safe message
Thread 2: Safe message
```

### Example: Avoiding Deadlocks with `std::lock`
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void task1() {
    std::lock(mtx1, mtx2); // Lock both mutexes without deadlock
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Task 1 completed\n";
}

void task2() {
    std::lock(mtx1, mtx2); // Lock both mutexes without deadlock
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Task 2 completed\n";
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
```
**Expected Output**:
```
Task 1 completed
Task 2 completed
```

---

## 7.4 Asynchronous Programming
Asynchronous programming allows you to execute tasks without blocking the main thread.

### Example: Using `std::async`
Available since **C++11**.
```cpp
#include <iostream>
#include <future>

int computeSum(int a, int b) {
    return a + b;
}

int main() {
    std::future<int> result = std::async(computeSum, 5, 10);

    std::cout << "Doing other work...\n";

    std::cout << "Result: " << result.get() << "\n"; // Waits for the result
    return 0;
}
```
**Expected Output**:
```
Doing other work...
Result: 15
```

### Example: Using `std::future` and `std::promise`
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>
#include <future>

void computeSquare(std::promise<int> promise, int value) {
    promise.set_value(value * value);
}

int main() {
    std::promise<int> promise;
    std::future<int> result = promise.get_future();

    std::thread t(computeSquare, std::move(promise), 5);

    std::cout << "Square: " << result.get() << "\n"; // Waits for the result

    t.join();
    return 0;
}
```
**Expected Output**:
```
Square: 25
```

---

## 7.5 Code Examples
### Example: Combining Threads and Synchronization
Available since **C++11**.
```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::thread t1(printNumbers, 1, 5);
    std::thread t2(printNumbers, 6, 10);

    t1.join();
    t2.join();

    return 0;
}
```
**Expected Output** (order of numbers may vary due to concurrency):
```
1 2 3 4 5 
6 7 8 9 10
```

---

## 7.6 Exercises
1. Create a program that spawns two threads to print numbers from 1 to 10. Use `std::mutex` to ensure thread safety. (Requires **C++11**)
2. Write a program that uses `std::async` to compute the factorial of a number asynchronously. (Requires **C++11**)
3. Use `std::promise` and `std::future` to pass a value from one thread to another. (Requires **C++11**)
4. Implement a program that demonstrates a deadlock and then resolves it using `std::lock`. (Requires **C++11**)

---

## 7.7 Summary
- Threads allow concurrent execution of tasks.
- Synchronization primitives like `std::mutex` and `std::lock_guard` prevent race conditions.
- Asynchronous programming with `std::async` and `std::future` enables non-blocking operations.
- Proper use of concurrency tools ensures safe and efficient multithreading.
- Ensure your compiler supports **C++11** or later for concurrency features.

---
