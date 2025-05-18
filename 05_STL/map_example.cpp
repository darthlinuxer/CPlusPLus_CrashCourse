#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ageMap;

    // Insert elements
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 35;

    // Access elements
    std::cout << "Alice's age: " << ageMap["Alice"] << "\n";

    // Iterate over the map
    std::cout << "All ages:\n";
    for (const auto& [name, age] : ageMap) {
        std::cout << name << ": " << age << "\n";
    }

    return 0;
}