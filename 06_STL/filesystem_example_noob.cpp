#include <iostream>
#include <windows.h>

int main() {
    // Define the current directory
    const char* path = "./*";

    // Use Windows API to iterate through the directory
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(path, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to open directory." << std::endl;
        return 1;
    }

    std::cout << "Current directory contents:\n";
    do {
        std::cout << findFileData.cFileName << "\n";
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return 0;
}

/*
Expected Output:
(Current directory contents will vary based on the files in the directory)
*/