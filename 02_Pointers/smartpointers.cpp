#include <iostream>
#include <memory>

// A simple class to demonstrate resource management
class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource released.\n"; }
    void sayHello() const { std::cout << "Hello from Resource!\n"; }
};

// Function demonstrating the use of std::unique_ptr
void uniquePointerExample() {
    // std::unique_ptr ensures exclusive ownership of the resource
    std::cout << "Unique pointer example starts.\n";
    {
        std::unique_ptr<Resource> uniqueRes = std::make_unique<Resource>();
        uniqueRes->sayHello(); // Access the resource
    } // Resource is automatically released when uniqueRes goes out of scope
    std::cout << "Unique pointer example ends.\n";
}

// Function demonstrating the use of std::shared_ptr
void sharedPointerExample() {
    // std::shared_ptr allows multiple shared ownership of the resource
    std::cout << "Shared pointer example starts.\n";
    std::shared_ptr<Resource> sharedRes1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> sharedRes2 = sharedRes1; // Shared ownership
        sharedRes2->sayHello(); // Access the resource
        std::cout << "Shared pointer use count: " << sharedRes1.use_count() << "\n";
    } // sharedRes2 goes out of scope, but the resource is not released yet
    std::cout << "Shared pointer use count after scope: " << sharedRes1.use_count() << "\n";
    std::cout << "Shared pointer example ends.\n";
}

// Function demonstrating the use of std::weak_ptr
void weakPointerExample() {
    // std::weak_ptr observes a resource managed by std::shared_ptr without affecting its lifetime
    std::cout << "Weak pointer example starts.\n";
    std::shared_ptr<Resource> sharedRes = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakRes = sharedRes; // Weak reference to the shared resource

    {
        // Lock the weak pointer to create a temporary shared pointer
        if (auto lockedRes = weakRes.lock()) {
            lockedRes->sayHello(); // Access the resource
            std::cout << "Weak pointer successfully locked.\n";
        } else {
            std::cout << "Weak pointer could not lock the resource.\n";
        }
    }

    // Reset the shared pointer, releasing the resource
    sharedRes.reset();
    if (auto lockedRes = weakRes.lock()) {
        lockedRes->sayHello();
    } else {
        std::cout << "Weak pointer could not lock the resource after shared pointer reset.\n";
    }
    std::cout << "Weak pointer example ends.\n";
}

int main() {
    // Demonstrate std::unique_ptr
    uniquePointerExample();

    // Demonstrate std::shared_ptr
    sharedPointerExample();

    // Demonstrate std::weak_ptr
    weakPointerExample();

    return 0;
}