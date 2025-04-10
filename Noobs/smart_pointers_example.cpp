// This file demonstrates the use of smart pointers (unique_ptr and shared_ptr) in C++.
// Why this is the right way:
// - Smart pointers manage memory automatically, reducing the risk of memory leaks.
// - They make ownership semantics explicit, improving code clarity.
// How a noob might do it:
// - A noob might use raw pointers, leading to potential memory management issues.

#include <iostream>
#include <memory>
#include <string>

// Demonstrating the use of unique_ptr and shared_ptr
struct Metadata {
    int id;
    std::string name;
};

void demonstrateSmartPointers() {
    // Using unique_ptr for exclusive ownership
    auto uniqueMetadata = std::make_unique<Metadata>(Metadata{1, "Unique"});
    std::cout << "Unique Metadata: " << uniqueMetadata->id << ", " << uniqueMetadata->name << std::endl;

    // Using shared_ptr for shared ownership
    auto sharedMetadata = std::make_shared<Metadata>(Metadata{2, "Shared"});
    auto anotherShared = sharedMetadata; // Shared ownership
    std::cout << "Shared Metadata: " << sharedMetadata->id << ", " << sharedMetadata->name << std::endl;
    std::cout << "Another Shared Metadata: " << anotherShared->id << ", " << anotherShared->name << std::endl;
}

int main() {
    demonstrateSmartPointers();
    return 0;
}

/* Expected Output:
Unique Metadata: 1, Unique
Shared Metadata: 2, Shared
Another Shared Metadata: 2, Shared
*/