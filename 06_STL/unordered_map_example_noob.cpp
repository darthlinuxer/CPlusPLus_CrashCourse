#include <iostream>
#include <vector>
#include <string>

class NoobHashMap {
private:
    struct KeyValuePair {
        std::string key;
        int value;
    };

    std::vector<KeyValuePair> data;

public:
    void insert(const std::string& key, int value) {
        for (auto& pair : data) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        data.push_back({key, value});
    }

    int get(const std::string& key) const {
        for (const auto& pair : data) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return 0; // Default value if key not found
    }

    void print() const {
        for (const auto& pair : data) {
            std::cout << pair.key << ": " << pair.value << "\n";
        }
    }
};

int main() {
    NoobHashMap wordCount;

    // Insert elements
    wordCount.insert("hello", 1);
    wordCount.insert("world", 2);

    // Access elements
    std::cout << "Count of 'hello': " << wordCount.get("hello") << "\n";

    // Iterate over the NoobHashMap
    std::cout << "Word counts:\n";
    wordCount.print();

    return 0;
}

/*
Expected Output:
Count of 'hello': 1
Word counts:
hello: 1
world: 2
*/