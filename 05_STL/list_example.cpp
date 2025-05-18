#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Create a list with initial elements
    list<int> lst = {1, 2, 3};

    // Add elements to the front and back
    lst.push_back(4);  // Add 4 to the back
    lst.push_front(0); // Add 0 to the front

    // Print all elements
    cout << "List elements: ";
    for (int x : lst) cout << x << " ";
    cout << "\n";

    // explain the differences between std::list vs std::vector
    // std::list is a doubly linked list, while std::vector is a dynamic array.
    // std::list allows for efficient insertion and deletion of elements at any position,
    // while std::vector provides fast random access to elements.
    // std::list has a larger memory overhead due to storing pointers for each element,
    // while std::vector has a smaller memory overhead but may require reallocation when growing.
    // std::list does not support direct indexing, while std::vector does.
    // std::list is better for frequent insertions and deletions, while std::vector is better for random access and cache performance.
    // std::list is not contiguous in memory, while std::vector is contiguous.
    // std::list has a slower iteration speed compared to std::vector due to non-contiguous memory.
    // std::list is not suitable for large data sets due to its overhead, while std::vector is more efficient for large data sets.
    // std::list is not cache-friendly, while std::vector is cache-friendly.
    // std::list is not suitable for algorithms that require random access, while std::vector is suitable for such algorithms.
    // std::list is not suitable for algorithms that require sorting, while std::vector is suitable for such algorithms.
    // std::list is not suitable for algorithms that require searching, while std::vector is suitable for such algorithms.
    // std::list is not suitable for algorithms that require binary search, while std::vector is suitable for such algorithms.
    // std::list is not suitable for algorithms that require sorting, while std::vector is suitable for such algorithms.
    // std::list is not suitable for algorithms that require searching, while std::vector is suitable for such algorithms.

    // access the third element
    auto it = lst.begin();
    advance(it, 2); // Move iterator to the third element
    cout << "Third element: " << *it << "\n"; // Output: 2

    list<string> planets {"Mercury", "Venus", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    auto pos = find(planets.begin(), planets.end(), "Mars");
    if (pos != planets.end()) planets.insert(pos, "Earth");
    planets.push_back("Pluto");
    cout << "Planets after insertion: ";
    for (const auto & planet : planets) {
        cout << planet << " ";
    }

    cout << "\n";
    // Sort the list of planets
    cout << "Planets after sorting ascending: ";
    planets.sort();
    for (const auto & planet : planets) {
        cout << planet << " ";
    }

    return 0;
}

/*
Expected Output:
List elements: 0 1 2 3 4 
Third element: 2
Planets after insertion: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune Pluto 
Planets after sorting ascending: Earth Jupiter Mars Mercury Neptune Pluto Saturn Uranus Venus 
*/