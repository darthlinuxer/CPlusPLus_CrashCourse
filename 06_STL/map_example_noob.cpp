#include <iostream>
#include <string>

class NoobMap {
private:
    struct KeyValuePair {
        std::string key;
        int value;
    };

    KeyValuePair data[100]; // Fixed-size array for simplicity
    int size;

public:
    NoobMap() : size(0) {}

    void insert(const std::string& key, int value) {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                data[i].value = value;
                return;
            }
        }
        data[size++] = {key, value};
    }

    int get(const std::string& key) const {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                return data[i].value;
            }
        }
        return 0; // Default value if key not found
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i].key << ": " << data[i].value << "\n";
        }
    }
};

int main() {
    NoobMap ageMap;

    // Insert elements
    ageMap.insert("Alice", 25);
    ageMap.insert("Bob", 30);
    ageMap.insert("Charlie", 35);

    // Access elements
    std::cout << "Alice's age: " << ageMap.get("Alice") << "\n";

    // Iterate over the map
    std::cout << "All ages:\n";
    ageMap.print();

    return 0;
}

/*
Expected Output:
Alice's age: 25
All ages:
Alice: 25
Bob: 30
Charlie: 35
*/