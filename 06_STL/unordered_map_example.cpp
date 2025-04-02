#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> wordCount;

    // Insert elements
    wordCount["hello"] = 1;
    wordCount["world"] = 2;

    // Access elements
    std::cout << "Count of 'hello': " << wordCount["hello"] << "\n";

    // Iterate over the unordered_map
    std::cout << "Word counts:\n";
    for (const auto& [word, count] : wordCount) {
        std::cout << word << ": " << count << "\n";
    }

    return 0;
}