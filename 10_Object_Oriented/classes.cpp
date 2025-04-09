#include <iostream>
#include <string>

class Person {
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Person person("John", 30);
    person.introduce();

    return 0;
}

/*
Hi, I'm John and I'm 30 years old.
*/