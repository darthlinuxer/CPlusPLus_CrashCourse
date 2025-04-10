#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> set1 = {1, 2, 3};
    std::vector<int> set2 = {3, 4, 5};
    std::set<int> intersection;

    // Intersect two sets (similar to LINQ's Intersect)
    for (int n : set1) {
        if (std::find(set2.begin(), set2.end(), n) != set2.end()) {
            intersection.insert(n);
        }
    }

    for (int n : intersection) {
        std::cout << n << " ";
    }

    return 0;
}