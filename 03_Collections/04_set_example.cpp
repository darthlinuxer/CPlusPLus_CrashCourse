#include <iostream>
#include <set>
#include <algorithm> // For std::set_union, std::set_intersection, etc.
#include <vector>    // For initializing set from a vector
#include <iterator>  // For std::inserter

// Custom struct for set example
struct Point {
    int x, y;
    // Needed for std::set if no custom comparator is provided, or for printing
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Custom comparator for Point (alternative to overloading operator<)
struct PointCompare {
    bool operator()(const Point& a, const Point& b) const {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

int main() {
    // ====================================================================
    // 1. Initialization and Basic Properties
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Properties ---" << std::endl;

    // Method 1: Using an initializer list (duplicates are automatically ignored)
    std::set<int> set1 = {5, 3, 8, 3, 1, 5}; // Contains {1, 3, 5, 8}
    std::cout << "Set 1 (from initializer list): ";
    for (int const& num : set1) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Method 2: Default constructor (empty set)
    std::set<int> set2;
    std::cout << "Set 2 (initially empty), size: " << set2.size() << ", empty: " << (set2.empty() ? "true" : "false") << std::endl;

    // Method 3: Copy constructor
    std::set<int> set3 = set1;
    std::cout << "Set 3 (copy of Set 1): ";
    for (int const& num : set3) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Method 4: Range constructor (e.g., from a vector)
    std::vector<int> vec_for_set = {10, 20, 10, 30, 20};
    std::set<int> set4(vec_for_set.begin(), vec_for_set.end()); // Contains {10, 20, 30}
    std::cout << "Set 4 (from vector {10, 20, 10, 30, 20}): ";
    for (int const& num : set4) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Size of Set 1: " << set1.size() << std::endl;
    std::cout << "Is Set 2 empty? " << (set2.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 2. Insertion
    // ====================================================================
    std::cout << "--- 2. Insertion ---" << std::endl;
    std::set<int> uniqueNumbers = {10, 20, 30};
    std::cout << "Initial uniqueNumbers: ";
    for (int const& num : uniqueNumbers) std::cout << num << " ";
    std::cout << "\n";

    // Insert a single element. `insert` returns a pair:
    // - first: an iterator to the inserted element (or the existing one if it was a duplicate)
    // - second: a boolean, true if insertion took place, false if element already existed.
    std::pair<std::set<int>::iterator, bool> result = uniqueNumbers.insert(15);
    if (result.second) {
        std::cout << "Element " << *result.first << " was inserted.\n";
    } else {
        std::cout << "Element " << *result.first << " already existed.\n";
    }

    result = uniqueNumbers.insert(20); // Attempt to insert a duplicate
    if (result.second) {
        std::cout << "Element " << *result.first << " was inserted.\n";
    } else {
        std::cout << "Element " << *result.first << " already existed.\n";
    }

    // `emplace()`: Constructs element in-place (more efficient for complex types).
    // Returns a pair like insert.
    auto emplace_result = uniqueNumbers.emplace(12);
    if (emplace_result.second) std::cout << "Element " << *emplace_result.first << " was emplaced.\n";

    // `emplace_hint()`: Constructs element in-place with a hint.
    // Hinting where 22 might go (after 20)
    // Insert with a hint (can be more efficient if hint is good)
    // Hinting where 25 might go (after 20)
    auto hint_it = uniqueNumbers.find(20);
    if (hint_it != uniqueNumbers.end()) {
        uniqueNumbers.insert(hint_it, 25); 
        std::cout << "Inserted 25 with a hint.\n";
    }
    hint_it = uniqueNumbers.find(20); // Re-find, as iterator might be invalidated by previous insert
    if (hint_it != uniqueNumbers.end()) {
        uniqueNumbers.emplace_hint(hint_it, 22);
        std::cout << "Emplaced 22 with a hint.\n";
    }

    // Insert a range of elements
    std::vector<int> more_numbers = {5, 35, 10}; // 10 is a duplicate
    uniqueNumbers.insert(more_numbers.begin(), more_numbers.end());
    std::cout << "uniqueNumbers after insertions: ";
    for (int const& num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 3. Element Access and Search
    // ====================================================================
    std::cout << "--- 3. Element Access and Search ---" << std::endl;
    // `find(key)`: Returns an iterator to the element, or `end()` if not found.
    int key_to_find = 15;
    auto find_it = uniqueNumbers.find(key_to_find);
    if (find_it != uniqueNumbers.end()) {
        std::cout << "Element " << key_to_find << " found in the set.\n";
    } else {
        std::cout << "Element " << key_to_find << " not found.\n";
    }

    // `count(key)`: Returns 1 if the element exists, 0 otherwise (for std::set).
    std::cout << "Count of 30 in set: " << uniqueNumbers.count(30) << std::endl;
    std::cout << "Count of 100 in set: " << uniqueNumbers.count(100) << std::endl;
    
    // Note: count returns size_type (unsigned) so ensure consistent comparisons

    // `contains(key)` (C++20): Checks if the key exists.
    #if __cplusplus >= 202002L
    std::cout << "Set contains 30 (C++20)? " << (uniqueNumbers.contains(30) ? "Yes" : "No") << std::endl;
    std::cout << "Set contains 100 (C++20)? " << (uniqueNumbers.contains(100) ? "Yes" : "No") << std::endl;
    #else
    std::cout << "uniqueNumbers.contains() requires C++20. Use find() or count() for older versions.\n";
    #endif


    // `lower_bound(key)`: Iterator to first element not less than key.
    // `upper_bound(key)`: Iterator to first element greater than key.
    auto lb = uniqueNumbers.lower_bound(18); // Should point to 20
    auto ub = uniqueNumbers.upper_bound(18); // Should also point to 20
    if (lb != uniqueNumbers.end()) std::cout << "Lower bound for 18: " << *lb << std::endl;
    if (ub != uniqueNumbers.end()) std::cout << "Upper bound for 18: " << *ub << std::endl;
    
    // `equal_range(key)`: Returns a pair of iterators (lower_bound, upper_bound) for the key.
    // For std::set, if the key exists, lower_bound points to it, and upper_bound points to the next element.
    // If the key doesn't exist, both point to where it would be inserted.
    auto range = uniqueNumbers.equal_range(20);
    std::cout << "Equal range for 20: ";
    if (range.first != uniqueNumbers.end()) {
        std::cout << "lower_bound is " << *range.first;
        if (range.second != uniqueNumbers.end()) {
            std::cout << ", upper_bound is " << *range.second;
        } else {
            std::cout << ", upper_bound is end()";
        }
    }
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 4. Removal
    // ====================================================================
    std::cout << "--- 4. Removal ---" << std::endl;
    std::cout << "Current uniqueNumbers: ";
    for (int const& num : uniqueNumbers) std::cout << num << " ";
    std::cout << "\n";

    // Erase by key
    size_t num_erased = uniqueNumbers.erase(15); // Erases 15
    std::cout << (num_erased > 0 ? "Element 15 erased.\n" : "Element 15 not found for erasure.\n");

    // Erase by iterator (e.g., erase the first element)
    if (!uniqueNumbers.empty()) {
        uniqueNumbers.erase(uniqueNumbers.begin());
        std::cout << "First element erased.\n";
    }

    // Erase a range of elements (e.g., elements >= 20 and < 30)
    // This will erase 20 and 25 from {10, 20, 25, 30, 35}
    auto start_erase = uniqueNumbers.lower_bound(20);
    auto end_erase = uniqueNumbers.lower_bound(30); // Elements up to, but not including, this
    uniqueNumbers.erase(start_erase, end_erase);
    std::cout << "Elements in range [20, 30) erased.\n";
    std::cout << "uniqueNumbers after some erasures: ";
    for (int const& num : uniqueNumbers) std::cout << num << " ";
    std::cout << "\n";

    // Conditional erase (e.g., remove all even numbers)
    // Note: The erase-remove idiom is not directly applicable to std::set.
    // Iterate and erase carefully.
    std::cout << "Erasing even numbers from current set: ";
    for (auto it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ) {
        if (*it % 2 == 0) { // If num is even
            std::cout << *it << " (even) erased, ";
            it = uniqueNumbers.erase(it); // Erase element and update iterator to the next one
        } else {
            ++it; // Move to the next element
        }
    }
    std::cout << "\n";
    std::cout << "uniqueNumbers after erasing even numbers: ";
    for (int const& num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // `clear()`: Removes all elements
    uniqueNumbers.clear();
    std::cout << "uniqueNumbers after clear(), size: " << uniqueNumbers.size() << ", empty: " << (uniqueNumbers.empty() ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // ====================================================================
    // 5. Custom Comparators
    // ====================================================================
    std::cout << "--- 5. Custom Comparators ---" << std::endl;
    // Set that stores elements in descending order
    std::set<int, std::greater<int>> descendingSet = {1, 5, 2, 8, 3};
    std::cout << "Descending set: ";
    for (int const& num : descendingSet) {
        std::cout << num << " "; // Output: 8 5 3 2 1
    }
    std::cout << "\n";
    std::cout << std::endl;

    // Set with custom objects and custom comparator
    std::cout << "Set with custom objects (Point) and custom comparator:\n";
    std::set<Point, PointCompare> pointSet;
    pointSet.insert({1, 2});
    pointSet.insert({0, 5});
    pointSet.insert({1, 0});
    pointSet.insert({0, 5}); // Duplicate, will be ignored

    for (const auto& p : pointSet) {
        std::cout << "Point(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\n";
    std::cout << std::endl;

    // ====================================================================
    // 6. Set Algorithms (from <algorithm>)
    // ====================================================================
    std::cout << "--- 6. Set Algorithms ---" << std::endl;
    std::set<int> sA = {1, 2, 3, 4, 5};
    std::set<int> sB = {4, 5, 6, 7, 8};
    std::cout << "Set A: "; for(int x:sA) std::cout << x << " "; std::cout << "\n";
    std::cout << "Set B: "; for(int x:sB) std::cout << x << " "; std::cout << "\n";

    // Union
    std::set<int> sUnion;
    std::set_union(sA.begin(), sA.end(), sB.begin(), sB.end(),
                   std::inserter(sUnion, sUnion.begin()));
    std::cout << "Union (A U B): ";
    for (int const& num : sUnion) std::cout << num << " ";
    std::cout << "\n";

    // Intersection
    std::set<int> sIntersection;
    std::set_intersection(sA.begin(), sA.end(), sB.begin(), sB.end(),
                          std::inserter(sIntersection, sIntersection.begin()));
    std::cout << "Intersection (A n B): ";
    for (int const& num : sIntersection) std::cout << num << " ";
    std::cout << "\n";

    // Difference (A - B)
    std::set<int> sDifference;
    std::set_difference(sA.begin(), sA.end(), sB.begin(), sB.end(),
                        std::inserter(sDifference, sDifference.begin()));
    std::cout << "Difference (A - B): ";
    for (int const& num : sDifference) std::cout << num << " ";
    std::cout << "\n";

    // Symmetric Difference (elements in A or B but not in both)
    std::set<int> sSymmetricDifference;
    std::set_symmetric_difference(sA.begin(), sA.end(), sB.begin(), sB.end(),
                                  std::inserter(sSymmetricDifference, sSymmetricDifference.begin()));
    std::cout << "Symmetric Difference: ";
    for (int const& num : sSymmetricDifference) std::cout << num << " ";
    std::cout << "\n";

    // `std::includes` (checks if one set is a subset of another)
    std::set<int> sSub = {2, 3};
    std::cout << "Is {2, 3} a subset of A? " 
              << (std::includes(sA.begin(), sA.end(), sSub.begin(), sSub.end()) ? "Yes" : "No") 
              << std::endl;
    std::cout << "Is B a subset of A? "
              << (std::includes(sA.begin(), sA.end(), sB.begin(), sB.end()) ? "Yes" : "No")
              << std::endl;

    return 0;
}

/*
--- 1. Initialization and Basic Properties ---
Set 1 (from initializer list): 1 3 5 8 
Set 2 (initially empty), size: 0, empty: true
Set 3 (copy of Set 1): 1 3 5 8 
Set 4 (from vector {10, 20, 10, 30, 20}): 10 20 30 
Size of Set 1: 4
Is Set 2 empty? Yes

--- 2. Insertion ---
Initial uniqueNumbers: 10 20 30 
Element 15 was inserted.
Element 20 already existed.
Element 12 was emplaced.
Inserted 25 with a hint.
Emplaced 22 with a hint.
uniqueNumbers after insertions: 5 10 12 15 20 22 25 30 35 

--- 3. Element Access and Search ---
Element 15 found in the set.
Count of 30 in set: 1
Count of 100 in set: 0
uniqueNumbers.contains() requires C++20. Use find() or count() for older versions.
Lower bound for 18: 20
Upper bound for 18: 20
Equal range for 20: lower_bound is 20, upper_bound is 22

--- 4. Removal ---
Current uniqueNumbers: 5 10 12 15 20 22 25 30 35 
Element 15 erased.
First element erased.
Elements in range [20, 30) erased.
uniqueNumbers after some erasures: 10 12 30 35 
Erasing even numbers from current set: 10 (even) erased, 12 (even) erased, 30 (even) erased, 
uniqueNumbers after erasing even numbers: 35 
uniqueNumbers after clear(), size: 0, empty: true

--- 5. Custom Comparators ---
Descending set: 8 5 3 2 1 

Set with custom objects (Point) and custom comparator:
Point(0, 5) Point(1, 0) Point(1, 2) 

--- 6. Set Algorithms ---
Set A: 1 2 3 4 5 
Set B: 4 5 6 7 8 
Union (A U B): 1 2 3 4 5 6 7 8 
Intersection (A n B): 4 5 
Difference (A - B): 1 2 3 
Symmetric Difference: 1 2 3 6 7 8 
Is {2, 3} a subset of A? Yes
Is B a subset of A? No
*/