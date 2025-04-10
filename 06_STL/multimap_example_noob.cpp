#include <iostream>
#include <vector>
#include <string>

class NoobMultiMap {
private:
    struct KeyValuePair {
        int key;
        std::string value;
    };

    std::vector<KeyValuePair> data;

public:
    void insert(int key, const std::string& value) {
        data.push_back({key, value});
    }

    void print() const {
        for (const auto& pair : data) {
            std::cout << pair.key << ": " << pair.value << "\n";
        }
    }
};

int main() {
    NoobMultiMap mmap;

    // Insert elements with duplicate keys
    mmap.insert(1, "One");
    mmap.insert(1, "Uno");
    mmap.insert(2, "Two");

    // Print all elements
    std::cout << "Multimap elements:\n";
    mmap.print();

    return 0;
}

/*
Expected Output:
Multimap elements:
1: One
1: Uno
2: Two
*/