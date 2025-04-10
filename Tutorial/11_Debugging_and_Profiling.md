# Chapter 11: C++ Debugging and Profiling

## 11.1 Introduction
Debugging and profiling are essential skills for C++ developers. Debugging helps identify and fix errors, while profiling helps optimize performance by identifying bottlenecks.

---

## 11.2 Debugging Tools
Debugging tools allow you to inspect the state of your program and trace its execution.

### Using GDB (GNU Debugger)
Available on Linux and macOS.
```bash
# Compile with debugging symbols
g++ -g program.cpp -o program

# Run the program in GDB
gdb ./program
```

#### Common GDB Commands
- `run`: Start the program.
- `break <line>`: Set a breakpoint at a specific line.
- `next`: Execute the next line of code.
- `print <variable>`: Print the value of a variable.
- `backtrace`: Show the call stack.

### Using Visual Studio Debugger
Available on Windows.
1. Open your project in Visual Studio.
2. Set breakpoints by clicking in the left margin of the editor.
3. Press `F5` to start debugging.
4. Use the Debug toolbar to step through code, inspect variables, and view the call stack.

---

## 11.3 Profiling Tools
Profiling tools help analyze the performance of your program.

### Using `gprof`
Available on Linux.
```bash
# Compile with profiling enabled
g++ -pg program.cpp -o program

# Run the program
./program

# Generate profiling data
gprof ./program gmon.out > analysis.txt
```

### Using Valgrind
Available on Linux.
```bash
# Run the program with Valgrind
valgrind --tool=callgrind ./program
```

### Using Visual Studio Profiler
Available on Windows.
1. Open your project in Visual Studio.
2. Go to `Debug > Performance Profiler`.
3. Select the profiling tools you want to use (e.g., CPU Usage, Memory Usage).
4. Click `Start` to begin profiling.

---

## 11.4 Best Practices
1. **Enable Debugging Symbols**:
   - Always compile with `-g` (GCC/Clang) or `/Zi` (MSVC) during development.

2. **Use Assertions**:
   - Use `assert` to catch logical errors during development.
   ```cpp
   #include <cassert>
   int main() {
       int x = 5;
       assert(x > 0); // Passes
       assert(x < 0); // Fails
       return 0;
   }
   ```

3. **Log Important Events**:
   - Use logging libraries like `spdlog` or `Boost.Log` to record program events.

4. **Profile Before Optimizing**:
   - Focus on optimizing bottlenecks identified by profiling tools.

---

## 11.5 Code Examples
### Example: Debugging with GDB
```cpp
#include <iostream>

int divide(int a, int b) {
    return a / b; // Potential division by zero
}

int main() {
    int x = 10, y = 0;
    std::cout << "Result: " << divide(x, y) << "\n"; // Debug this line
    return 0;
}
```
**Steps**:
1. Compile with `g++ -g program.cpp -o program`.
2. Run `gdb ./program`.
3. Set a breakpoint: `break 7`.
4. Start the program: `run`.
5. Inspect variables: `print x`, `print y`.

---

### Example: Profiling with `gprof`
```cpp
#include <iostream>
#include <vector>
#include <numeric>

void computeSum(const std::vector<int>& numbers) {
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << "\n";
}

int main() {
    std::vector<int> numbers(1000000, 1);
    computeSum(numbers);
    return 0;
}
```
**Steps**:
1. Compile with `g++ -pg program.cpp -o program`.
2. Run `./program`.
3. Generate profiling data: `gprof ./program gmon.out > analysis.txt`.

---

## 11.6 Exercises
1. Use GDB to debug a program with a division by zero error.
2. Profile a program using `gprof` and identify the function consuming the most time.
3. Use Valgrind to analyze the memory usage of a program.
4. Set up and use the Visual Studio Profiler to analyze the performance of a program.

---

## 11.7 Summary
- Debugging tools like GDB and Visual Studio Debugger help identify and fix errors.
- Profiling tools like `gprof`, Valgrind, and Visual Studio Profiler help optimize performance.
- Follow best practices like enabling debugging symbols and profiling before optimizing.

---
