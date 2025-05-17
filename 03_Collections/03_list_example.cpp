#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator> // For std::advance

using namespace std;

int main() {
    // ====================================================================
    // 1. Initialization and Basic Operations
    // ====================================================================
    std::cout << "--- 1. Initialization and Basic Operations ---" << std::endl;
    // Create a list with an initializer list
    list<int> lst = {1, 2, 3};

    // `push_back()`: Add an element to the back
    lst.push_back(4);  // Add 4 to the back
    // `push_front()`: Add an element to the front
    lst.push_front(0); // Add 0 to the front

    // Displaying elements using a range-based for loop
    cout << "List elements: ";
    for (int x : lst) cout << x << " ";
    cout << "\n";

    // `front()` and `back()`: Access first and last elements
    cout << "Front element: " << lst.front() << ", Back element: " << lst.back() << endl;

    // `size()` and `empty()`
    cout << "List size: " << lst.size() << ", Is empty? " << (lst.empty() ? "Yes" : "No") << endl;
    cout << endl;

    // ====================================================================
    // 2. Accessing Elements (No direct indexing like lst[i])
    // ====================================================================
    std::cout << "--- 2. Accessing Elements ---" << std::endl;
    // To access an element by position, you need to use iterators.
    auto it = lst.begin();
    advance(it, 2); // Move iterator to the third element
    cout << "Third element: " << *it << "\n"; // Output: 2
    cout << endl;

    // ====================================================================
    // 3. Insertion and Erasure
    // ====================================================================
    std::cout << "--- 3. Insertion and Erasure ---" << std::endl;
    list<string> planets {"Mercury", "Venus", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    cout << "Initial planets: "; for(const auto& p : planets) cout << p << " "; cout << "\n";

    // `insert()`: Insert elements at a specific position.
    auto pos = find(planets.begin(), planets.end(), "Mars");
    if (pos != planets.end()) {
        planets.insert(pos, "Earth"); // Insert "Earth" before "Mars"
    }
    cout << "Planets after inserting Earth: "; for(const auto& p : planets) cout << p << " "; cout << "\n";

    // `erase()`: Remove elements.
    pos = find(planets.begin(), planets.end(), "Jupiter");
    if (pos != planets.end()) {
        pos = planets.erase(pos); // Erase "Jupiter", pos now points to "Saturn"
        cout << "Erased Jupiter. Next element is: " << *pos << endl;
    }
    cout << "Planets after erasing Jupiter: "; for(const auto& p : planets) cout << p << " "; cout << "\n";

    // `pop_front()` and `pop_back()`
    planets.pop_front(); // Remove "Mercury"
    planets.pop_back();  // Remove "Neptune" (if Pluto wasn't added yet)
    cout << "Planets after pop_front and pop_back: "; for(const auto& p : planets) cout << p << " "; cout << "\n";
    cout << endl;

    // ====================================================================
    // 4. List-specific Operations
    // ====================================================================
    std::cout << "--- 4. List-specific Operations ---" << std::endl;
    list<int> num_list = {1, 2, 2, 3, 4, 4, 4, 5, 2};
    cout << "num_list: "; for(int n : num_list) cout << n << " "; cout << "\n";

    // `remove(value)`: Removes all elements equal to a given value.
    num_list.remove(2);
    cout << "After remove(2): "; for(int n : num_list) cout << n << " "; cout << "\n";

    // `remove_if(predicate)`: Removes elements for which the predicate is true.
    num_list.remove_if([](int n) { return n > 3; }); // Remove elements greater than 3
    cout << "After remove_if(n > 3): "; for(int n : num_list) cout << n << " "; cout << "\n";

    // `unique()`: Removes consecutive duplicate elements. (List should be sorted for global uniqueness)
    list<int> dup_list = {1, 1, 2, 3, 3, 3, 2, 2, 4};
    cout << "dup_list before unique: "; for(int n : dup_list) cout << n << " "; cout << "\n";
    dup_list.unique();
    cout << "dup_list after unique (consecutive): "; for(int n : dup_list) cout << n << " "; cout << "\n";
    dup_list.sort();
    dup_list.unique();
    cout << "dup_list sorted and then unique (global): "; for(int n : dup_list) cout << n << " "; cout << "\n";

    // `sort()`: Sorts the list.
    planets.push_back("Pluto"); // Add Pluto back for sorting
    cout << "Planets after sorting ascending: ";
    planets.sort();
    for (const auto & planet : planets) cout << planet << " ";
    cout << "\n";

    // `reverse()`: Reverses the order of elements.
    planets.reverse();
    cout << "Planets after reversing: "; for(const auto& p : planets) cout << p << " "; cout << "\n";

    // `splice()`: Transfers elements from one list to another.
    list<string> dwarf_planets = {"Ceres", "Eris"};
    auto insert_here = planets.begin();
    advance(insert_here, 2); // Position after 2 elements
    planets.splice(insert_here, dwarf_planets); // Moves all elements from dwarf_planets
    cout << "Planets after splicing dwarf_planets: "; for(const auto& p : planets) cout << p << " "; cout << "\n";
    cout << "dwarf_planets is now empty: " << (dwarf_planets.empty() ? "Yes" : "No") << endl;

    // `merge()`: Merges two sorted lists. Both lists must be sorted.
    list<int> list1 = {1, 3, 5};
    list<int> list2 = {2, 4, 6};
    list1.merge(list2); // Elements are moved from list2 to list1. list2 becomes empty.
    cout << "Merged list1: "; for(int n : list1) cout << n << " "; cout << "\n";
    cout << "list2 after merge is empty: " << (list2.empty() ? "Yes" : "No") << endl;
    cout << endl;

    // ====================================================================
    // 5. Key Differences: std::list vs std::vector
    // ====================================================================
    std::cout << "--- 5. Key Differences: std::list vs std::vector ---" << std::endl;
    std::cout << "std::list (Doubly Linked List):\n"
              << "  - Pros: Fast insertions/deletions anywhere (O(1) if iterator is known).\n"
              << "  - Cons: No random access (operator[]). Accessing elements by index is O(n).\n"
              << "          Higher memory overhead per element (stores pointers).\n"
              << "          Elements not contiguous in memory (can lead to cache misses).\n"
              << "  - Use when: Frequent insertions/deletions in the middle of the sequence.\n"
              << "              Don't need random access.\n\n";

    std::cout << "std::vector (Dynamic Array):\n"
              << "  - Pros: Fast random access (operator[]) (O(1)).\n"
              << "          Elements contiguous in memory (good cache performance).\n"
              << "          Lower memory overhead per element.\n"
              << "  - Cons: Insertions/deletions in the middle or beginning are slow (O(n)).\n"
              << "          Reallocation can be costly if capacity is exceeded.\n"
              << "  - Use when: Frequent random access is needed.\n"
              << "              Insertions/deletions mostly at the end.\n"
              << "              Cache performance is important.\n";

    return 0;
}

/*
--- 1. Initialization and Basic Operations ---
List elements: 0 1 2 3 4 
Front element: 0, Back element: 4
List size: 5, Is empty? No

--- 2. Accessing Elements ---
Third element: 2

--- 3. Insertion and Erasure ---
Initial planets: Mercury Venus Mars Jupiter Saturn Uranus Neptune 
Planets after inserting Earth: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune 
Erased Jupiter. Next element is: Saturn
Planets after erasing Jupiter: Mercury Venus Earth Mars Saturn Uranus Neptune 
Planets after pop_front and pop_back: Venus Earth Mars Saturn Uranus 

--- 4. List-specific Operations ---
num_list: 1 2 2 3 4 4 4 5 2 
After remove(2): 1 3 4 4 4 5 
After remove_if(n > 3): 1 3 
dup_list before unique: 1 1 2 3 3 3 2 2 4 
dup_list after unique (consecutive): 1 2 3 2 4 
dup_list sorted and then unique (global): 1 2 3 4 
Planets after sorting ascending: Earth Mars Pluto Saturn Uranus Venus 
Planets after reversing: Venus Uranus Saturn Pluto Mars Earth 
Planets after splicing dwarf_planets: Venus Uranus Ceres Eris Saturn Pluto Mars Earth 
dwarf_planets is now empty: Yes
Merged list1: 1 2 3 4 5 6 
list2 after merge is empty: Yes

--- 5. Key Differences: std::list vs std::vector ---
std::list (Doubly Linked List):
  - Pros: Fast insertions/deletions anywhere (O(1) if iterator is known).
  - Cons: No random access (operator[]). Accessing elements by index is O(n).
          Higher memory overhead per element (stores pointers).
          Elements not contiguous in memory (can lead to cache misses).
  - Use when: Frequent insertions/deletions in the middle of the sequence.
              Don't need random access.

std::vector (Dynamic Array):
  - Pros: Fast random access (operator[]) (O(1)).
          Elements contiguous in memory (good cache performance).
          Lower memory overhead per element.
  - Cons: Insertions/deletions in the middle or beginning are slow (O(n)).
          Reallocation can be costly if capacity is exceeded.
  - Use when: Frequent random access is needed.
              Insertions/deletions mostly at the end.
              Cache performance is important.
*/