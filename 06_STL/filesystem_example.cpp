#include <iostream>
#include <filesystem>

int main() {
    // Define the current directory
    std::filesystem::path path = ".";

    // Iterate through the directory and print file names
    std::cout << "Current directory contents:\n";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path() << "\n";
    }

    return 0;
}

/*
Expected Output:
(Current directory contents will vary based on the files in the directory)
*/