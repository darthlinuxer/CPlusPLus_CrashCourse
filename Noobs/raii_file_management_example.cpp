// This file demonstrates the concept of RAII (Resource Acquisition Is Initialization) for file management.
// RAII ensures that resources like file handles are properly released when they go out of scope.
// Why this is the right way:
// - It eliminates the need for manual resource management, reducing the risk of resource leaks.
// - The file is automatically closed when the std::ifstream object goes out of scope.
// How a noob might do it:
// - A noob might forget to close the file explicitly, leading to resource leaks.
// - They might use raw file handles (e.g., fopen/fclose) instead of RAII-enabled classes like std::ifstream.

#include <iostream>
#include <fstream>
#include <string>

// Demonstrating the use of RAII for file management
void readFromFile(const std::string &fileName) {
    // Using RAII with std::ifstream
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    // No need to explicitly close the file; RAII ensures it is closed
}

int main() {
    const std::string fileName = "example.txt";
    readFromFile(fileName);
    return 0;
}

/* Expected Output:
Contents of the file "example.txt" will be printed line by line, or an error message if the file does not exist.
*/