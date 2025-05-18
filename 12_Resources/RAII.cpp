// Demonstrates the RAII (Resource Acquisition Is Initialization) principle.

// RAII is a programming idiom used in C++ to manage resource allocation and deallocation automatically. It ensures that resources are acquired during object creation and released during object destruction, preventing resource leaks and ensuring proper cleanup.
// This is particularly useful for managing resources like file handles, memory, and network connections.
// The RAII principle is implemented using constructors and destructors in C++ classes. When an object is created, its constructor acquires the resource, and when the object goes out of scope, its destructor releases the resource. This guarantees that resources are properly managed even in the presence of exceptions or early returns from functions.
// The RAII principle is a key feature of C++ and is widely used in modern C++ programming to ensure resource safety and exception safety.
// It is a fundamental concept that helps prevent resource leaks and ensures that resources are properly cleaned up, making C++ a powerful language for systems programming and resource management.
// In this example, we demonstrate RAII by creating a class that manages a file resource. The file is opened in the constructor and closed in the destructor, ensuring that the file is properly managed throughout the object's lifetime.

// In modern C++ you should normally never need the delete keyword anymore
// A dynamically allocated object should always be managed by a smart pointer (std::unique_ptr or std::shared_ptr).
// Memory is a resource and to acquire you should initialize a smart pointer

#include <iostream>
#include <fstream> // For file handling.
#include <stdexcept> // For runtime_error exceptions.

class FileHandler {
    std::ofstream file; // Resource: file stream.

public:
    // Constructor: Acquires the resource (opens the file).
    // This ensures the resource is initialized as soon as the object is created.
    FileHandler(const std::string& filename) {
        file.open(filename); // Attempt to open the file.
        if (!file.is_open()) { // Check if the file was successfully opened.
            throw std::runtime_error("Failed to open file."); // Throw an exception if the resource acquisition fails.
        }
        std::cout << "File opened successfully.\n"; // Log success.
    }

    // Destructor: Releases the resource (closes the file).
    // This ensures the resource is properly cleaned up when the object goes out of scope.
    ~FileHandler() {
        if (file.is_open()) { // Check if the file is still open.
            file.close(); // Close the file to release the resource.
            std::cout << "File closed successfully.\n"; // Log success.
        }
    }

    // Member function to write to the file.
    // Demonstrates safe usage of the acquired resource.
    void write(const std::string& text) {
        if (file.is_open()) { // Ensure the file is open before writing.
            file << text << "\n"; // Write the text to the file.
        } else {
            throw std::runtime_error("File is not open for writing."); // Handle unexpected cases.
        }
    }
};

int main() {
    try {
        // Create a FileHandler object.
        // The file is opened as part of the object's construction.
        FileHandler fileHandler("example.txt");

        // Use the FileHandler object to write to the file.
        // Demonstrates safe usage of the resource.
        fileHandler.write("Hello, RAII!");

        // The FileHandler object goes out of scope here.
        // Its destructor is automatically called, ensuring the file is closed.
    } catch (const std::exception& e) {
        // Handle any exceptions that occur during resource acquisition or usage.
        std::cerr << "Error: " << e.what() << "\n";
    }

    // The program ends here, and all resources are guaranteed to be cleaned up.
    return 0;
}

/*
File opened successfully.
File closed successfully.
*/