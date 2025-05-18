#include <iostream>

class NoobUniquePtr {
private:
    int* ptr;

public:
    // Constructor
    explicit NoobUniquePtr(int* p = nullptr) : ptr(p) {}

    // Destructor
    ~NoobUniquePtr() {
        delete ptr;
    }

    // Move constructor
    NoobUniquePtr(NoobUniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    NoobUniquePtr& operator=(NoobUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Delete copy constructor and copy assignment operator
    NoobUniquePtr(const NoobUniquePtr&) = delete;
    NoobUniquePtr& operator=(const NoobUniquePtr&) = delete;

    // Dereference operator
    int& operator*() const {
        return *ptr;
    }
};

int main() {
    // Create a NoobUniquePtr
    NoobUniquePtr up(new int(42));
    std::cout << "NoobUniquePtr value: " << *up << "\n";

    // Transfer ownership to another NoobUniquePtr
    NoobUniquePtr up2 = std::move(up);

    if (!&up) {
        std::cout << "Original NoobUniquePtr is now null\n";
    }

    std::cout << "Transferred NoobUniquePtr value: " << *up2 << "\n";

    return 0;
}

/*
Expected Output:
NoobUniquePtr value: 42
Original NoobUniquePtr is now null
Transferred NoobUniquePtr value: 42
*/