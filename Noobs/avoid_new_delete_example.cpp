// This file demonstrates the use of smart pointers instead of raw new and delete.
// Why this is the right way:
// - Smart pointers automatically manage memory, reducing the risk of memory leaks and dangling pointers.
// - They make the code safer and easier to maintain.
// How a noob might do it:
// - A noob might use raw new and delete, leading to potential memory management issues.

#include <iostream>
#include <memory>
#include <string>

// Demonstrating the use of smart pointers instead of new and delete
class Widget {
public:
    Widget(int id, const std::string &name) : id{id}, name{name} {
        std::cout << "Widget created: " << id << ", " << name << std::endl;
    }

    ~Widget() {
        std::cout << "Widget destroyed: " << id << ", " << name << std::endl;
    }

private:
    int id;
    std::string name;
};

void demonstrateSmartPointerUsage() {
    // Using unique_ptr for automatic memory management
    auto widget = std::make_unique<Widget>(1, "SmartWidget");
    // No need to manually delete the widget
}

int main() {
    demonstrateSmartPointerUsage();
    return 0;
}

/* Expected Output:
Widget created: 1, SmartWidget
Widget destroyed: 1, SmartWidget
*/