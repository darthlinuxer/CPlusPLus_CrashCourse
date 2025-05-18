#include <iostream>
#include <thread>
#include <atomic>

// Function to compute factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Shared variable to store the result
std::atomic<int> result;

// Thread function to compute factorial
void computeFactorial(int n) {
    result = factorial(n);
}

int main() {
    // Launch factorial computation in a separate thread
    std::thread worker(computeFactorial, 5);

    // Do other work while the factorial is being computed
    std::cout << "Computing factorial...\n";

    // Wait for the thread to finish
    worker.join();

    // Get the result
    std::cout << "Factorial result: " << result.load() << "\n";

    return 0;
}

/*
Expected Output:
Computing factorial...
Factorial result: 120
*/