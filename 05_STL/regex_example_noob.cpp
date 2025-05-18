#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// Function to find all sequences of digits in a string
std::vector<std::string> findMatches(const std::string& input) {
    std::vector<std::string> matches;
    std::string currentMatch;

    for (char ch : input) {
        if (std::isdigit(ch)) {
            currentMatch += ch;
        } else if (!currentMatch.empty()) {
            matches.push_back(currentMatch);
            currentMatch.clear();
        }
    }

    if (!currentMatch.empty()) {
        matches.push_back(currentMatch);
    }

    return matches;
}

int main() {
    // Input string
    std::string input = "The year is 2025 and the month is 04.";

    // Find all matches
    std::vector<std::string> matches = findMatches(input);

    // Print the first match
    if (!matches.empty()) {
        std::cout << "First match: " << matches[0] << "\n";
    }

    // Print all matches
    std::cout << "All matches: ";
    for (const std::string& match : matches) {
        std::cout << match << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
First match: 2025
All matches: 2025 04
*/