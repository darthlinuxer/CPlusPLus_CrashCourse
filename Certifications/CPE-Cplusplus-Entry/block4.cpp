#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure
struct Person {
    string name;
    int age;
};

int main() {
    // Using structure
    Person p1 = {"Alice", 30};
    cout << p1.name << " is " << p1.age << " years old.\n";

    // Vector of structures
    vector<Person> people = {{"Bob", 25}, {"Carol", 28}};
    for (const auto& person : people) {
        cout << person.name << " - " << person.age << endl;
    }

    // Strings
    string greeting = "Hello";
    string name = "World";
    string message = greeting + ", " + name + "!";
    cout << message << endl;

    // Comparing strings
    if (greeting == "Hello") {
        cout << "Greeting matched.\n";
    }

    return 0;
}
// Output:
/*
Alice is 30 years old.
Bob - 25
Carol - 28
Hello, World!
Greeting matched.
*/
