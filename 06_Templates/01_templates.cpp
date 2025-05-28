// Templates resolve at compile time, allowing for type-safe generic programming.
// This is a powerful feature of C++ that allows for code reuse and flexibility.
// Templates can be functions or classes, and they can work with any data type.

#include <iostream>
template <class T>
T max(T const &a, T const &b)
{
    return (a > b) ? a : b;
};

class Person
{
private:
    int age;

public:
    Person(int a) : age(a) {}

    int getAge() const
    {
        return age;
    }

    // Overloaded operator to compare two Person objects
    bool operator>(const Person &other) const
    {
        return age > other.age;
    }

    // person + int operator overload
    // This allows adding an integer to a Person object, which increases the age.
    // It returns a new Person object with the updated age.
    Person operator+(int age) const
    {
        return Person(this->age + age);
    }

    // Overloaded operator to add a Person object and an integer
    // This allows adding two Person objects together, summing their ages.
    // It returns a new Person object with the combined age.
    Person operator+(Person const& other) const 
    {
        //other.age = 10; // This line would cause a compilation error because 'other' is const.
        return Person(this->age + other.age);
    }

    // Overloaded operator to compare two Person objects using the spaceship operator
    // This operator allows for three-way comparison, which is useful for sorting and ordering.
    // It returns a std::strong_ordering result.
    auto operator <=>(Person const& other) const
    {
        return age <=> other.age;
    }

    // Friend function to overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Person &p)
    {
        os << "Person age: " << p.age;
        return os;
    }
};

// Overloaded operator to add an integer to a Person object
Person operator+(int age, const Person &p)
{
    // will use the internal operator+ of Person class
    return p + age;
}


int main()
{
    std::cout << max(3, 7) << std::endl;           // Calls max<int>
    std::cout << max<double>(3, 2.0) << std::endl; // Calls max<double>
    std::cout << max('a', 'z') << std::endl;       // Calls max<char>
    std::cout << max(Person(40), Person(30)).getAge() << std::endl; // Calls max<Person>
    std::cout << max(Person(25), Person(30)) << std::endl; // uses the overloaded << operator
    return 0;
}