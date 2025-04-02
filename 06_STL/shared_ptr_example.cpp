#include <iostream>
#include <memory>

int main() {
    // Create a shared_ptr
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    std::cout << "Shared pointer value: " << *sp << "\n";

    // Create a weak_ptr from the shared_ptr
    std::weak_ptr<int> wp = sp;

    // Check if weak_ptr is valid
    if (auto locked = wp.lock()) { // Lock weak_ptr to access the shared resource
        std::cout << "Weak pointer value: " << *locked << "\n";
    } else {
        std::cout << "Weak pointer is expired\n";
    }

    // Reset the shared_ptr
    sp.reset();

    // Check weak_ptr again
    if (auto locked = wp.lock()) {
        std::cout << "Weak pointer value: " << *locked << "\n";
    } else {
        std::cout << "Weak pointer is expired\n";
    }

    return 0;
}

/*
Expected Output:
Shared pointer value: 42
Weak pointer value: 42
Weak pointer is expired
*/