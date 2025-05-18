#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> set1 = {1, 2, 3};
    std::vector<int> set2 = {3, 4, 5};
    std::set<int> difference;

    // Except (elements in set1 but not in set2, similar to LINQ's Except)
    for (int n : set1) {
        if (std::find(set2.begin(), set2.end(), n) == set2.end()) {
            difference.insert(n);
        }
    }

    for (int n : difference) {
        std::cout << n << " ";
    }

    return 0;
}