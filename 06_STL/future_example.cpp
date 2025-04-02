#include <iostream>
#include <future>
#include <thread>

// Function to compute factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    // Launch factorial computation asynchronously
    std::future<int> result = std::async(std::launch::async, factorial, 5);

    // Do other work while the factorial is being computed
    std::cout << "Computing factorial...\n";

    // Get the result
    std::cout << "Factorial result: " << result.get() << "\n";

    return 0;
}

/*
Expected Output:
Computing factorial...
Factorial result: 120
*/