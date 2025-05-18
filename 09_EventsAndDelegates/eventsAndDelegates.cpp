#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <mutex>

// This C++ code implements an event-handling system similar to the event and delegate mechanism in C#.
// In C#, events allow communication between objects, where a publisher notifies subscribers when something happens.
// Delegates in C# are type-safe function pointers that enable methods to be passed as parameters or assigned to events.

// In this C++ implementation:
// 1. The Event class is analogous to an event in C#. It manages a list of listeners (subscribers) and provides methods
//    to add, remove, and trigger these listeners.
// 2. Instead of C#'s built-in event keyword, this implementation uses a std::vector of std::weak_ptr to store listeners.
//    This ensures that listeners are not kept alive unnecessarily, similar to how C# events do not prevent garbage collection of subscribers.
// 3. Thread-safety is achieved using std::mutex, which is comparable to C#'s thread-safe event handling.
// 4. The trigger method in the Event class is equivalent to invoking an event in C#. It iterates through the list of listeners
//    and calls each one with the provided value.
// 5. The main function demonstrates how to create listeners, add them to an event, and trigger the event, similar to subscribing
//    to and raising events in C#.

// Event class to manage listeners and trigger events
class Event {
public:
    // Add a listener (delegate) to the event
    void addListener(const std::shared_ptr<std::function<void(int)>>& listener) {
        std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
        listeners.push_back(listener);
    }

    // Remove a listener from the event
    void removeListener(const std::shared_ptr<std::function<void(int)>>& listener) {
        std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
        listeners.erase(
            std::remove_if(listeners.begin(), listeners.end(),
                           [&listener](const std::weak_ptr<std::function<void(int)>>& weakListener) {
                               auto sharedListener = weakListener.lock();
                               return sharedListener == listener;
                           }),
            listeners.end());
    }

    // Trigger the event and notify all listeners
    void trigger(int value) const {
        std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
        for (const auto& weakListener : listeners) {
            if (auto listener = weakListener.lock()) { // Check if the listener is still valid
                (*listener)(value); // Call the listener
            }
        }
    }

private:
    mutable std::mutex mutex; // Mutex for thread-safety
    std::vector<std::weak_ptr<std::function<void(int)>>> listeners; // List of weak pointers to listeners
};

// A class that listens to events
class Listener {
public:
    Listener(const std::string& name) : name(name) {}

    // Method to handle the event
    void onEvent(int value) const {
        std::cout << name << " received event with value: " << value << "\n";
    }

private:
    std::string name;
};

int main() {
    Event onValueChanged; // Create an event

    // Create listeners
    auto listener1 = std::make_shared<Listener>("Listener1");
    auto listener2 = std::make_shared<Listener>("Listener2");

    // Add listeners to the event
    auto listener1Callback = std::make_shared<std::function<void(int)>>(
        [listener1](int value) { listener1->onEvent(value); });
    auto listener2Callback = std::make_shared<std::function<void(int)>>(
        [listener2](int value) { listener2->onEvent(value); });

    onValueChanged.addListener(listener1Callback);
    onValueChanged.addListener(listener2Callback);

    // Add a standalone lambda as a listener
    auto standaloneCallback = std::make_shared<std::function<void(int)>>([](int value) {
        std::cout << "Standalone lambda received value: " << value << "\n";
    });
    onValueChanged.addListener(standaloneCallback);

    // Trigger the event
    std::cout << "Triggering event with value 42...\n";
    onValueChanged.trigger(42);

    // Remove a listener
    onValueChanged.removeListener(listener1Callback);

    // Trigger the event again
    std::cout << "Triggering event with value 100...\n";
    onValueChanged.trigger(100);

    return 0;
}