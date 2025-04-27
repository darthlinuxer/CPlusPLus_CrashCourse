#include <iostream>
#include <memory>

// A simple class to demonstrate resource management
class Resource
{
public:
    Resource() { std::cout << "Resource acquired.\n"; }              // Constructor: prints when the resource is created
    ~Resource() { std::cout << "Resource released.\n"; }             // Destructor: prints when the resource is destroyed
    void sayHello() const { std::cout << "Hello from Resource!\n"; } // A simple method to demonstrate access
};

// Function demonstrating the use of std::unique_ptr
void uniquePointerExample()
{
    // std::unique_ptr ensures exclusive ownership of the resource
    std::cout << "Unique pointer example starts.\n";
    { // Create a scope to demonstrate unique_ptr
        // std::unique_ptr automatically manages the resource
        std::unique_ptr<Resource> uniqueRes = std::make_unique<Resource>();
        uniqueRes->sayHello(); // Access the resource through the unique_ptr
    } // Resource is automatically released when uniqueRes goes out of scope
    std::cout << "Unique pointer example ends.\n";
}

// Function demonstrating the use of std::shared_ptr
void sharedPointerExample()
{
    // std::shared_ptr allows multiple shared ownership of the resource
    std::cout << "Shared pointer example starts.\n";
    {
        std::shared_ptr<Resource> sharedRes1 = std::make_shared<Resource>();
        {
            // Create another shared_ptr sharing ownership of the same resource
            std::shared_ptr<Resource> sharedRes2 = sharedRes1;                           // Shared ownership
            sharedRes2->sayHello();                                                      // Access the resource through the second shared_ptr
            std::cout << "Shared pointer use count: " << sharedRes1.use_count() << "\n"; // Print the reference count
        } // sharedRes2 goes out of scope, but the resource is not released yet
        std::cout << "Shared pointer use count after scope: " << sharedRes1.use_count() << "\n"; // Reference count decreases
    } // sharedRes1 goes out of scope, and the resource is released
    std::cout << "Shared pointer example ends.\n";
}

// Function demonstrating the use of std::weak_ptr
void weakPointerExample()
{
    // std::weak_ptr observes a resource managed by std::shared_ptr without affecting its lifetime
    std::cout << "Weak pointer example starts.\n";
    std::shared_ptr<Resource> sharedRes = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakRes = sharedRes; // Weak reference to the shared resource

    {
        // Lock the weak pointer to create a temporary shared pointer if the resource is still available
        if (auto lockedRes = weakRes.lock())
        {                          // Check if the resource is still valid
            lockedRes->sayHello(); // Access the resource through the locked shared_ptr
            std::cout << "Weak pointer successfully locked.\n";
        }
        else
        {
            std::cout << "Weak pointer could not lock the resource.\n";
        }
    } // Temporary shared_ptr (lockedRes) goes out of scope here

    // Reset the shared pointer, releasing the resource
    sharedRes.reset(); // The resource is destroyed here since no shared_ptr owns it anymore
    if (auto lockedRes = weakRes.lock())
    {                          // Attempt to lock the weak_ptr again
        lockedRes->sayHello(); // This won't execute since the resource is already destroyed
    }
    else
    {
        std::cout << "Weak pointer could not lock the resource after shared pointer reset.\n";
    }
    std::cout << "Weak pointer example ends.\n";
}

int main()
{
    // Demonstrate std::unique_ptr
    std::cout << std::string(50, '=') << "\n";
    uniquePointerExample();
    std::cout << std::string(50, '=') << "\n";

    // Demonstrate std::shared_ptr
    sharedPointerExample();
    std::cout << std::string(50, '=') << "\n";

    // Demonstrate std::weak_ptr
    weakPointerExample();
    std::cout << std::string(50, '=') << "\n";

    return 0;
}

/*
Unique pointer example starts.
Resource acquired.
Hello from Resource!
Resource released.
Unique pointer example ends.
Shared pointer example starts.
Resource acquired.
Hello from Resource!
Shared pointer use count: 2
Shared pointer use count after scope: 1
Shared pointer example ends.
Resource released.
Weak pointer example starts.
Resource acquired.
Hello from Resource!
Weak pointer successfully locked.
Resource released.
Weak pointer could not lock the resource after shared pointer reset.
Weak pointer example ends.
*/