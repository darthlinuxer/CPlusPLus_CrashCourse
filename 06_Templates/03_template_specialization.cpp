#include "Accumulator.h"

class Person
{
private:
    int age;

public:
    Person(int a) : age(a) {}
    int getAge() const { return age; }
};

template <>
class Acumulator<Person>
{
private:
    int sum;

public:
    Acumulator(int start) : sum(start) {
        std::cout << "Constructor with initial value called for a template specialization" << std::endl;
    }
    int operator+(Person const &t)
    {
        return sum + t.getAge();
    }
    friend std::ostream &operator<<(std::ostream &os, const Acumulator &acc)
    {
        return os << "Total Acc: " << acc.sum << std::endl;
    }
};

int main()
{
    Person p1(30);
    Person p2(40);
    Acumulator<Person> acc(10);
    std::cout << acc 
                << acc + p1 << "\n"
                << acc + p2;
    return 0;
}