#include <iostream>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>
#endif

#ifdef _WIN32
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
#elif defined(__linux__) || defined(__APPLE__)
int main() {
    // Define the current directory
    const char* path = ".";

    // Open the directory
    DIR* dir = opendir(path);
    if (dir == nullptr) {
        std::cerr << "Error: Unable to open directory." << std::endl;
        return 1;
    }

    std::cout << "Current directory contents:\n";
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Construct the full path to the entry
        std::string fullPath = std::string(path) + "/" + entry->d_name;

        // Get file status to check if it's a directory
        struct stat fileStat;
        if (stat(fullPath.c_str(), &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                std::cout << entry->d_name << " (directory)\n";
            } else {
                std::cout << entry->d_name << "\n";
            }
        } else {
            std::cerr << "Error: Unable to get file status for " << entry->d_name << std::endl;
        }
    }

    closedir(dir);
    return 0;
}
#endif

/*
Expected Output:
(Current directory contents will vary based on the files in the directory)
*/