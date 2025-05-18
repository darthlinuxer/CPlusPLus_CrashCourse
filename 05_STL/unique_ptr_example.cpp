#include <iostream>
#include <memory>

int main() {
    // Create a unique_ptr
    std::unique_ptr<int> up = std::make_unique<int>(42);
    std::cout << "Unique pointer value: " << *up << "\n";

    // Transfer ownership to another unique_ptr
    std::unique_ptr<int> up2 = std::move(up);

    if (!up) {
        std::cout << "Original unique_ptr is now null\n";
    }

    std::cout << "Transferred unique pointer value: " << *up2 << "\n";

    return 0;
}

/*
Expected Output:
Unique pointer value: 42
Original unique_ptr is now null
Transferred unique pointer value: 42
*/