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

    bool operator>(const Person &other) const
    {
        return age > other.age;
    }

    // Friend function to overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Person &p)
    {
        os << "Person age: " << p.age;
        return os;
    }
};


int main()
{
    std::cout << max(3, 7) << std::endl;           // Calls max<int>
    std::cout << max<double>(3, 2.0) << std::endl; // Calls max<double>
    std::cout << max('a', 'z') << std::endl;       // Calls max<char>
    std::cout << max(Person(40), Person(30)).getAge() << std::endl; // Calls max<Person>
    std::cout << max(Person(25), Person(30)) << std::endl; // uses the overloaded << operator
    return 0;
}