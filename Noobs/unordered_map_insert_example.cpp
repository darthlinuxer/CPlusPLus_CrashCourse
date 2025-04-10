// This file demonstrates the use of std::unordered_map's operator[] for inserting elements if they don't exist.
// Why this is the right way:
// - It simplifies code by combining insertion and access in a single operation.
// - It ensures that elements are initialized with default values if they don't exist.
// How a noob might do it:
// - A noob might use separate checks and insertions, leading to more verbose and error-prone code.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Demonstrating std::unordered_map operator[] inserting elements if they don't exist
std::unordered_map<std::string, int> countWords(const std::vector<std::string> &words) {
    std::unordered_map<std::string, int> counts;
    for (const auto &word : words) {
        counts[word]++; // Inserts the word with a default value of 0 if it doesn't exist
    }
    return counts;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    auto wordCounts = countWords(words);

    for (const auto &pair : wordCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

/* Expected Output:
apple: 3
banana: 2
orange: 1
*/