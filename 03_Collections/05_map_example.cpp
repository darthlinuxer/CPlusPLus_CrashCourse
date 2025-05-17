#include <iostream>
#include <map>
#include <string>
#include <utility> // For std::pair, std::make_pair

int main() {
    // ====================================================================
    // 1. Initialization and Basic Properties
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Properties ---" << std::endl;
    // Method 1: Default constructor
    std::map<std::string, int> ageMap;
    std::cout << "ageMap initially empty: " << (ageMap.empty() ? "Yes" : "No") << ", size: " << ageMap.size() << std::endl;

    // Method 2: Initializer list (C++11)
    std::map<std::string, int> cityPopulations = {
        {"New York", 8398748},
        {"London", 8982000},
        {"Tokyo", 13929286}
    };
    std::cout << "cityPopulations size: " << cityPopulations.size() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Insertion of Elements
    // ====================================================================
    std::cout << "--- 2. Insertion of Elements ---" << std::endl;
    // Method A: Using operator[]
    // If key "Alice" doesn't exist, it's created. If it exists, its value is updated.
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 35;
    std::cout << "After operator[] insertions: ";
    for (const auto& [name, age] : ageMap) {
        std::cout << name << ": " << age << "\n";
    }

    // Method B: Using insert() with std::pair
    // insert() returns std::pair<iterator, bool>. bool is true if insertion happened.
    auto result = ageMap.insert(std::pair<std::string, int>("David", 22));
    if (result.second) {
        std::cout << "David inserted successfully. Age: " << result.first->second << std::endl;
    }
    result = ageMap.insert(std::make_pair("Alice", 26)); // Alice already exists
    if (!result.second) {
        std::cout << "Alice already exists. Current age: " << result.first->second << " (not updated by this insert call)" << std::endl;
    }

    // Method C: Using emplace() (constructs element in-place, C++11)
    // More efficient for complex key/value types.
    auto emplace_result = ageMap.emplace("Eve", 28);
    if (emplace_result.second) {
        std::cout << "Eve emplaced successfully. Age: " << emplace_result.first->second << std::endl;
    }

    // Method D: Using try_emplace() (C++17)
    // Inserts only if key doesn't exist. Doesn't modify if key exists.
    auto try_emplace_res = ageMap.try_emplace("Frank", 40); // Frank is new
    if (try_emplace_res.second) std::cout << "Frank try_emplace successful. Age: " << try_emplace_res.first->second << std::endl;
    try_emplace_res = ageMap.try_emplace("Alice", 30); // Alice exists, value not updated
    if (!try_emplace_res.second) std::cout << "Alice try_emplace failed (already exists). Age: " << try_emplace_res.first->second << std::endl;

    // Method E: Using insert_or_assign() (C++17)
    // Inserts if key doesn't exist, or assigns new value if key exists.
    auto ins_assign_res = ageMap.insert_or_assign("Alice", 27); // Alice exists, age updated
    std::cout << "Alice insert_or_assign. New age: " << ins_assign_res.first->second << ". Inserted: " << ins_assign_res.second << std::endl;
    ins_assign_res = ageMap.insert_or_assign("Grace", 32); // Grace is new
    std::cout << "Grace insert_or_assign. Age: " << ins_assign_res.first->second << ". Inserted: " << ins_assign_res.second << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 3. Accessing Elements
    // ====================================================================
    std::cout << "--- 3. Accessing Elements ---" << std::endl;
    // Using operator[]:
    // - If key exists, returns a reference to its value.
    // - If key doesn't exist, it inserts a new element with that key and default-constructed value, then returns a reference.
    std::cout << "Bob's age using []: " << ageMap["Bob"] << "\n";
    std::cout << "Accessing 'Unknown' using []: " << ageMap["Unknown"] << " (created with default value 0 for int)\n";

    // Using at():
    // - If key exists, returns a reference to its value.
    // - If key doesn't exist, throws std::out_of_range. Safer for read-only access if key might not exist.
    std::cout << "Charlie's age using at(): " << ageMap.at("Charlie") << "\n";
    try {
        std::cout << ageMap.at("MissingKey") << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Caught exception for at('MissingKey'): " << oor.what() << std::endl;
    }
    std::cout << std::endl;

    // ====================================================================
    // 4. Searching for Elements
    // ====================================================================
    std::cout << "--- 4. Searching for Elements ---" << std::endl;
    // `find(key)`: Returns an iterator to the element if found, otherwise returns map::end().
    auto it_find = ageMap.find("Eve");
    if (it_find != ageMap.end()) {
        std::cout << "Found Eve, age: " << it_find->second << std::endl;
    } else {
        std::cout << "Eve not found." << std::endl;
    }

    // `count(key)`: Returns 1 if key exists, 0 otherwise (since keys are unique in std::map).
    std::cout << "Count of 'David': " << ageMap.count("David") << std::endl;
    std::cout << "Count of 'NonExistent': " << ageMap.count("NonExistent") << std::endl;

    // `contains(key)` (C++20): Returns true if key exists, false otherwise.
    #if __cplusplus >= 202002L
    std::cout << "Map contains 'Frank' (C++20)? " << (ageMap.contains("Frank") ? "Yes" : "No") << std::endl;
    #else
    std::cout << "map.contains() requires C++20. Use find() or count().\n";
    #endif
    std::cout << std::endl;

    // ====================================================================
    // 5. Iterating Over the Map
    // ====================================================================
    std::cout << "--- 5. Iterating Over the Map ---" << std::endl;
    // Elements in std::map are sorted by key.
    std::cout << "All ages (sorted by name):\n";
    for (const auto& pair : ageMap) { // Using range-based for loop (C++11) with structured binding (C++17)
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    // Or explicitly: for (const std::pair<const std::string, int>& pair : ageMap)
    std::cout << std::endl;

    // ====================================================================
    // 6. Removing Elements
    // ====================================================================
    std::cout << "--- 6. Removing Elements ---" << std::endl;
    // `erase(key)`: Removes element by key. Returns number of elements erased (0 or 1).
    size_t num_erased = ageMap.erase("Unknown");
    std::cout << (num_erased > 0 ? "'Unknown' erased." : "'Unknown' not found.") << std::endl;

    // `erase(iterator)`: Removes element at iterator position.
    auto it_to_erase = ageMap.find("Bob");
    if (it_to_erase != ageMap.end()) {
        ageMap.erase(it_to_erase); // Erases Bob
        std::cout << "Bob erased using iterator." << std::endl;
    }

    std::cout << "Map after some erasures:\n";
    for (const auto& [name, age] : ageMap) {
        std::cout << name << ": " << age << "\n";
    }

    // `clear()`: Removes all elements.
    ageMap.clear();
    std::cout << "Map after clear(): size = " << ageMap.size() << ", empty = " << (ageMap.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
/* 
--- 1. Initialization and Basic Properties ---
ageMap initially empty: Yes, size: 0
cityPopulations size: 3

--- 2. Insertion of Elements ---
After operator[] insertions: Alice: 25
Bob: 30
Charlie: 35
David inserted successfully. Age: 22
Alice already exists. Current age: 25 (not updated by this insert call)
Eve emplaced successfully. Age: 28
Frank try_emplace successful. Age: 40
Alice try_emplace failed (already exists). Age: 25
Alice insert_or_assign. New age: 27. Inserted: 0
Grace insert_or_assign. Age: 32. Inserted: 1

--- 3. Accessing Elements ---
Bob's age using []: 30
Accessing 'Unknown' using []: 0 (created with default value 0 for int)
Charlie's age using at(): 35

--- 4. Searching for Elements ---
Found Eve, age: 28
Count of 'David': 1
Count of 'NonExistent': 0
map.contains() requires C++20. Use find() or count().

--- 5. Iterating Over the Map ---
All ages (sorted by name):
Alice: 27
Bob: 30
Charlie: 35
David: 22
Eve: 28
Frank: 40
Grace: 32
Unknown: 0

--- 6. Removing Elements ---
'Unknown' erased.
Bob erased using iterator.
Map after some erasures:
Alice: 27
Charlie: 35
David: 22
Eve: 28
Frank: 40
Grace: 32
Map after clear(): size = 0, empty = Yes
Caught exception for at('MissingKey'): map::at
*/