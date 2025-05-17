#include <iostream>
#include <unordered_set>
#include <string> // For string example

// For custom hash example
struct MyPoint {
    int x, y;

    // Default constructor
    MyPoint() : x(0), y(0) {}
    
    // Constructor with parameters
    MyPoint(int x_val, int y_val) : x(x_val), y(y_val) {}

    bool operator==(const MyPoint& other) const {
        return x == other.x && y == other.y;
    }
};

// Custom hash function for MyPoint
struct MyPointHash {
    std::size_t operator()(const MyPoint& p) const {
        auto h1 = std::hash<int>{}(p.x);
        auto h2 = std::hash<int>{}(p.y);
        return h1 ^ (h2 << 1); // Combine hashes
    }
};

int main() {
    // ====================================================================
    // 1. Initialization and Basic Insertion
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Insertion ---" << std::endl;
    // `std::unordered_set` stores unique elements in a hash table.
    // Order of elements is not guaranteed.
    std::unordered_set<int> uset = {1, 2, 3, 4};
    std::cout << "Initial uset: ";
    for (int x : uset) std::cout << x << " ";
    std::cout << "\n";

    // `insert(value)`: Inserts an element. Returns std::pair<iterator, bool>.
    // bool is true if insertion took place (element was new).
    auto result = uset.insert(5);
    if (result.second) std::cout << "Element 5 inserted.\n";
    result = uset.insert(3); // Attempt to insert duplicate
    if (!result.second) std::cout << "Element 3 already exists, not inserted again.\n";

    // `emplace(args...)`: Constructs element in-place (C++11).
    uset.emplace(6);
    std::cout << "uset after emplace(6): ";
    for (int x : uset) std::cout << x << " ";
    std::cout << "\n";
    std::cout << "Size of uset: " << uset.size() << ", empty: " << (uset.empty() ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Searching for Elements
    // ====================================================================
    std::cout << "--- 2. Searching for Elements ---" << std::endl;
    // `find(key)`: Returns an iterator to the element if found, otherwise `uset.end()`.
    if (uset.find(3) != uset.end()) {
        std::cout << "Element 3 found\n";
    }
    if (uset.find(100) == uset.end()) {
        std::cout << "Element 100 not found\n";
    }

    // `count(key)`: Returns 1 if the element exists, 0 otherwise.
    std::cout << "Count of 4: " << uset.count(4) << std::endl;
    std::cout << "Count of 7: " << uset.count(7) << std::endl;

    // `contains(key)` (C++20): Checks if the key exists.
    #if __cplusplus >= 202002L
    std::cout << "uset contains 5 (C++20)? " << (uset.contains(5) ? "Yes" : "No") << std::endl;
    #else
    std::cout << "uset.contains() requires C++20. Use find() or count().\n";
    #endif
    std::cout << std::endl;

    // ====================================================================
    // 3. Removing Elements
    // ====================================================================
    std::cout << "--- 3. Removing Elements ---" << std::endl;
    // `erase(key)`: Removes the element with the given key. Returns number of elements removed (0 or 1).
    size_t num_erased = uset.erase(2);
    if (num_erased > 0) std::cout << "Element 2 erased.\n";

    // `erase(iterator)`: Removes the element at the iterator position.
    auto it_erase = uset.find(4);
    if (it_erase != uset.end()) {
        uset.erase(it_erase);
        std::cout << "Element 4 erased using iterator.\n";
    }
    std::cout << "uset after erasures: ";
    for (int x : uset) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 4. Bucket Interface and Load Factor
    // ====================================================================
    std::cout << "--- 4. Bucket Interface and Load Factor ---" << std::endl;
    std::cout << "Bucket count: " << uset.bucket_count() << std::endl;
    std::cout << "Load factor: " << uset.load_factor() << std::endl;
    // `rehash(n)` and `reserve(n)` are also available.
    uset.rehash(50); // Request at least 50 buckets
    std::cout << "After rehash(50), bucket count: " << uset.bucket_count() << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 5. Unordered_set with Custom Type
    // ====================================================================
    std::cout << "--- 5. Unordered_set with Custom Type ---" << std::endl;
    std::unordered_set<MyPoint, MyPointHash> pointSet;
    pointSet.insert({1, 2});
    pointSet.insert({3, 4});
    pointSet.emplace(1, 2); // Duplicate, will be ignored

    std::cout << "Custom point set elements:\n";
    for (const auto& p : pointSet) {
        std::cout << "Point(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\n";
    std::cout << "\nNote: Standard set algorithms like std::set_union are not directly efficient for unordered_sets "
              << "as they require sorted ranges. Manual iteration would be needed for such operations.\n";

    return 0;
}

/*
--- 1. Initialization and Basic Insertion ---
Initial uset: 4 3 2 1 
Element 5 inserted.
Element 3 already exists, not inserted again.
uset after emplace(6): 6 5 4 3 2 1 
Size of uset: 6, empty: false

--- 2. Searching for Elements ---
Element 3 found
Element 100 not found
Count of 4: 1
Count of 7: 0
uset.contains() requires C++20. Use find() or count().

--- 3. Removing Elements ---
Element 2 erased.
Element 4 erased using iterator.
uset after erasures: 6 5 3 1 

--- 4. Bucket Interface and Load Factor ---
Bucket count: 13
Load factor: 0.307692
After rehash(50), bucket count: 53

--- 5. Unordered_set with Custom Type ---
Custom point set elements:
Point(3, 4) Point(1, 2) 

Note: Standard set algorithms like std::set_union are not directly efficient for unordered_sets as they require sorted ranges. Manual iteration would be needed for such operations.
*/