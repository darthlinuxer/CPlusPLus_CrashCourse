#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx; // Mutex for synchronization
std::condition_variable cv; // Condition variable for signaling
bool ready = false; // Shared state for signaling

// Function to demonstrate basic thread execution
void basicThreadFunction(int id) {
    std::cout << "Thread " << id << " is running." << std::endl;
}

// Function to demonstrate mutex usage
void threadWithMutex(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " has acquired the lock." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread " << id << " is releasing the lock." << std::endl;
}

// Function to demonstrate condition variable usage
void threadWithConditionVariable(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until ready is true
    std::cout << "Thread " << id << " is proceeding after the signal." << std::endl;
}

int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;

    // Basic thread creation and joining
    std::cout << "Basic Thread Example:" << std::endl;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(basicThreadFunction, i);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    threads.clear();

    // Mutex example
    std::cout << "\nMutex Example:" << std::endl;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(threadWithMutex, i);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    threads.clear();

    // Condition variable example
    std::cout << "\nCondition Variable Example:" << std::endl;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(threadWithConditionVariable, i);
    }

    // Simulate some work in main thread
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all(); // Notify all waiting threads

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}