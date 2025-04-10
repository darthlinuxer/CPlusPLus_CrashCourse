// This file demonstrates the use of stack allocation instead of heap allocation in C++.
// Why this is the right way:
// - Stack allocation is faster and automatically managed, reducing the risk of memory leaks.
// - It simplifies code by avoiding manual memory management.
// How a noob might do it:
// - A noob might use heap allocation unnecessarily, leading to more complex and error-prone code.

#include <iostream>
#include <string>

// Demonstrating the use of stack allocation instead of heap allocation
struct Record {
    int id;
    std::string name;
};

void unnecessaryHeapAllocations() {
    // Using stack allocation instead of heap allocation
    Record customer = {0, "James"};
    Record other = {1, "Someone"};

    // Print the records
    std::cout << "Customer: " << customer.id << ", " << customer.name << std::endl;
    std::cout << "Other: " << other.id << ", " << other.name << std::endl;
}

int main() {
    unnecessaryHeapAllocations();
    return 0;
}

/* Expected Output:
Customer: 0, James
Other: 1, Someone
*/