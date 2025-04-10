// This file demonstrates the dangers of using const_cast in C++.
// Why this is the right way:
// - It highlights the risks of modifying const objects and encourages avoiding const_cast.
// - It promotes safer alternatives and better coding practices.
// How a noob might do it:
// - A noob might use const_cast without understanding its implications, leading to undefined behavior.
// - They might modify const objects, breaking the contract of const correctness.

#include <iostream>
#include <unordered_map>
#include <string>

// Demonstrating the dangers of using const_cast
const std::string &
moreFrequent(const std::unordered_map<std::string, int> &wordCounts,
             const std::string &word1,
             const std::string &word2) {
    // Avoid using const_cast to modify const objects
    auto &counts = const_cast<std::unordered_map<std::string, int> &>(wordCounts);
    return counts[word1] > counts[word2] ? word1 : word2;
}

int main() {
    std::unordered_map<std::string, int> wordCounts = {
        {"apple", 5},
        {"banana", 3}
    };

    const std::string &result = moreFrequent(wordCounts, "apple", "banana");
    std::cout << "More frequent word: " << result << std::endl;

    return 0;
}

/* Expected Output:
More frequent word: apple
*/