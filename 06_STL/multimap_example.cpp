#include <iostream>
#include <map>

int main() {
    // Create a multimap with duplicate keys
    std::multimap<int, std::string> mmap;

    mmap.insert({1, "One"});
    mmap.insert({1, "Uno"});
    mmap.insert({2, "Two"});

    // Print all elements
    std::cout << "Multimap elements:\n";
    for (const auto& [key, value] : mmap) {
        std::cout << key << ": " << value << "\n";
    }

    return 0;
}

/*
Expected Output:
Multimap elements:
1: One
1: Uno
2: Two
*/