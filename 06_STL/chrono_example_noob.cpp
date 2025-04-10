#include <iostream>
#include <ctime>

int main() {
    // Record the start time
    std::clock_t start = std::clock();

    // Simulate some work with a 1-second delay
    for (volatile int i = 0; i < 100000000; ++i) {
        // Busy-wait loop to simulate delay
    }

    // Record the end time
    std::clock_t end = std::clock();

    // Calculate the elapsed time
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Elapsed time: " << elapsed << " seconds\n";

    return 0;
}

/*
Expected Output:
Elapsed time: ~1 seconds (may vary slightly depending on system performance)
*/