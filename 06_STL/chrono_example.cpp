#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Record the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Simulate some work with a 1-second delay
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";

    return 0;
}

/*
Expected Output:
Elapsed time: 1 seconds
*/