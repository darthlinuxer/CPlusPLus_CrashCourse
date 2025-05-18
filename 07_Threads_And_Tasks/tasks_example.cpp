#include <iostream>
#include <thread>
#include <future>
#include <chrono> // For std::chrono::seconds

// Function to simulate a long-running task
// This function takes an integer input, simulates a delay, and returns the input multiplied by 2.
int longRunningTask(int input) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a 2-second delay
    return input * 2;
}

int main() {
    // Demonstrate asynchronous tasks in C++

    // Step 1: Start an asynchronous task using std::async
    // std::async launches a task in a separate thread and returns a std::future object.
    std::cout << "Starting async task..." << std::endl;
    std::future<int> result = std::async(std::launch::async, longRunningTask, 10);

    // Step 2: Perform other work while the task runs in the background
    // This demonstrates the non-blocking nature of asynchronous tasks.
    std::cout << "Doing other work..." << std::endl;

    // Step 3: Retrieve the result of the asynchronous task
    // The .get() method blocks until the task is complete and retrieves the result.
    std::cout << "Result: " << result.get() << std::endl;

    // Additional Notes:
    // - std::async can be used with std::launch::async (to force asynchronous execution)
    //   or std::launch::deferred (to execute the task only when .get() or .wait() is called).
    // - std::future is a mechanism to retrieve the result of an asynchronous operation.
    // - std::this_thread::sleep_for is used to simulate delays in tasks.

    // Example of deferred execution:
    std::cout << "Starting deferred task..." << std::endl;
    std::future<int> deferredResult = std::async(std::launch::deferred, longRunningTask, 5);

    // The task will not run until .get() or .wait() is called.
    std::cout << "Deferred task result: " << deferredResult.get() << std::endl;

    return 0;
}