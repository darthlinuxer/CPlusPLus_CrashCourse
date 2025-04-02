#include <iostream>
#include <regex>
#include <string>

int main() {
    // Define a regex pattern
    std::regex pattern(R"(\d+)"); // Matches one or more digits

    // Input string
    std::string input = "The year is 2025 and the month is 04.";

    // Search for matches
    std::smatch matches;
    if (std::regex_search(input, matches, pattern)) {
        std::cout << "First match: " << matches[0] << "\n";
    }

    // Find all matches
    std::cout << "All matches: ";
    auto words_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto words_end = std::sregex_iterator();
    for (auto it = words_begin; it != words_end; ++it) {
        std::cout << it->str() << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
First match: 2025
All matches: 2025 04
*/