#include <iostream>
#include <vector>
#include <string>

struct Person {
    int id;
    std::string name;
};

struct Order {
    int personId;
    std::string product;
};

int main() {
    std::vector<Person> people = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    std::vector<Order> orders = {{1, "Laptop"}, {2, "Phone"}, {1, "Tablet"}};

    // Join people with their orders (similar to LINQ's Join)
    for (const auto& person : people) {
        for (const auto& order : orders) {
            if (person.id == order.personId) {
                std::cout << person.name << " ordered " << order.product << "\n";
            }
        }
    }

    return 0;
}