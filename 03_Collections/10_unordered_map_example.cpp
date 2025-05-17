#include <iostream>
#include <unordered_map>
#include <string>
#include <utility> // For std::pair, std::make_pair

// For custom hash example
struct MyKey {
    int id;
    std::string name;

    bool operator==(const MyKey& other) const {
        return id == other.id && name == other.name;
    }
};

// Custom hash function for MyKey
struct MyKeyHash {
    std::size_t operator()(const MyKey& k) const {
        // A simple hash combining hashes of id and name
        return std::hash<int>()(k.id) ^ (std::hash<std::string>()(k.name) << 1);
    }
};

int main() {
    // ====================================================================
    // 1. Initialization and Basic Properties
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Properties ---" << std::endl;
    // `std::unordered_map` stores key-value pairs in a hash table.
    // Order of elements is not guaranteed and may change upon rehash.
    std::unordered_map<std::string, int> wordCount;
    std::cout << "wordCount initially empty: " << (wordCount.empty() ? "Yes" : "No") << ", size: " << wordCount.size() << std::endl;

    // Initializer list (C++11)
    std::unordered_map<std::string, double> prices = {
        {"apple", 0.5}, {"banana", 0.25}, {"orange", 0.75}
    };
    std::cout << "prices map size: " << prices.size() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Insertion of Elements
    // ====================================================================
    std::cout << "--- 2. Insertion of Elements ---" << std::endl;
    // Method A: Using operator[]
    wordCount["hello"] = 1;
    wordCount["world"] = 2;
    wordCount["hello"]++; // Increment count for "hello"

    // Method B: Using insert() with std::pair or std::make_pair
    // insert() returns std::pair<iterator, bool>. bool is true if insertion happened.
    auto result = wordCount.insert(std::make_pair("test", 1));
    if (result.second) std::cout << "'test' inserted. Count: " << result.first->second << std::endl;

    // Method C: Using emplace() (constructs element in-place, C++11)
    wordCount.emplace("another", 5);
    std::cout << "After insertions, wordCount['hello']: " << wordCount["hello"] << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 3. Accessing Elements
    // ====================================================================
    std::cout << "--- 3. Accessing Elements ---" << std::endl;
    // Using operator[]:
    // - If key exists, returns a reference to its value.
    // - If key doesn't exist, it inserts a new element with that key and default-constructed value.
    std::cout << "Count of 'world' using []: " << wordCount["world"] << "\n";
    std::cout << "Accessing 'new_word' using []: " << wordCount["new_word"] << " (created with default 0)\n";

    // Using at():
    // - If key exists, returns a reference to its value.
    // - If key doesn't exist, throws std::out_of_range.
    try {
        std::cout << "Count of 'hello' using at(): " << wordCount.at("hello") << "\n";
        std::cout << wordCount.at("non_existent_key") << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Caught exception for at('non_existent_key'): " << oor.what() << std::endl;
    }
    std::cout << std::endl;

    // ====================================================================
    // 4. Searching and Iterating
    // ====================================================================
    std::cout << "--- 4. Searching and Iterating ---" << std::endl;
    // `find(key)`: Returns an iterator to the element if found, otherwise returns end().
    auto it_find = wordCount.find("test");
    if (it_find != wordCount.end()) {
        std::cout << "Found 'test', count: " << it_find->second << std::endl;
    }

    // `count(key)`: Returns 1 if key exists, 0 otherwise.
    std::cout << "Count of 'world': " << wordCount.count("world") << std::endl;

    // `contains(key)` (C++20)
    #if __cplusplus >= 202002L
    std::cout << "Map contains 'another' (C++20)? " << (wordCount.contains("another") ? "Yes" : "No") << std::endl;
    #endif

    std::cout << "\nAll word counts (order not guaranteed):\n";
    for (const auto& [word, count] : wordCount) {
        std::cout << word << ": " << count << "\n";
    }
    std::cout << std::endl;

    // ====================================================================
    // 5. Removing Elements
    // ====================================================================
    std::cout << "--- 5. Removing Elements ---" << std::endl;
    // `erase(key)`: Removes element by key. Returns number of elements erased (0 or 1).
    wordCount.erase("new_word");
    std::cout << "'new_word' erased.\n";

    // `erase(iterator)`: Removes element at iterator position.
    auto it_erase = wordCount.find("test");
    if (it_erase != wordCount.end()) wordCount.erase(it_erase);
    std::cout << "'test' erased using iterator.\n";
    std::cout << "wordCount size after erasures: " << wordCount.size() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 6. Bucket Interface and Load Factor
    // ====================================================================
    std::cout << "--- 6. Bucket Interface and Load Factor ---" << std::endl;
    std::cout << "Bucket count: " << wordCount.bucket_count() << std::endl;
    std::cout << "Load factor: " << wordCount.load_factor() << std::endl;
    std::cout << "Max load factor: " << wordCount.max_load_factor() << std::endl;

    // `reserve(n)`: Reserves at least n buckets if n > bucket_count().
    // `rehash(n)`: Sets the number of buckets to n and rehashes the container.
    wordCount.rehash(100); // Request 100 buckets
    std::cout << "After rehash(100), bucket count: " << wordCount.bucket_count() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 7. Unordered_map with Custom Key Type
    // ====================================================================
    std::cout << "--- 7. Unordered_map with Custom Key Type ---" << std::endl;
    std::unordered_map<MyKey, std::string, MyKeyHash> customMap;
    customMap.emplace(MyKey{1, "apple"}, "Fruit");
    customMap.emplace(MyKey{2, "banana"}, "Fruit");
    customMap[MyKey{3, "carrot"}] = "Vegetable";

    std::cout << "Custom map elements:\n";
    for (const auto& [key, value] : customMap) {
        std::cout << "Key(id:" << key.id << ", name:" << key.name << ") -> Value: " << value << std::endl;
    }

    return 0;
}
/*
--- 1. Initialization and Basic Properties ---
wordCount initially empty: Yes, size: 0
prices map size: 3

--- 2. Insertion of Elements ---
'test' inserted. Count: 1
After insertions, wordCount['hello']: 2

--- 3. Accessing Elements ---
Count of 'world' using []: 2
Accessing 'new_word' using []: 0 (created with default 0)
Count of 'hello' using at(): 2
Caught exception for at('non_existent_key'): unordered_map::at

--- 4. Searching and Iterating ---
Found 'test', count: 1
Count of 'world': 1

All word counts (order not guaranteed):
new_word: 0
another: 5
test: 1
world: 2
hello: 2

--- 5. Removing Elements ---
'new_word' erased.
'test' erased using iterator.
wordCount size after erasures: 3

--- 6. Bucket Interface and Load Factor ---
Bucket count: 13
Load factor: 0.230769
Max load factor: 1
After rehash(100), bucket count: 103

--- 7. Unordered_map with Custom Key Type ---
Custom map elements:
Key(id:3, name:carrot) -> Value: Vegetable
Key(id:2, name:banana) -> Value: Fruit
Key(id:1, name:apple) -> Value: Fruit
*/