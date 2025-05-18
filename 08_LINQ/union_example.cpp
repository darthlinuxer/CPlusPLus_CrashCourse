#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> set1 = {1, 2, 3};
    std::vector<int> set2 = {3, 4, 5};
    std::set<int> unionSet(set1.begin(), set1.end());
    unionSet.insert(set2.begin(), set2.end());

    // Union of two sets (similar to LINQ's Union)
    for (int n : unionSet) {
        std::cout << n << " ";
    }

    return 0;
}