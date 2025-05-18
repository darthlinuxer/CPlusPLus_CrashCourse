#include <iostream>

template <class T>
class Acumulator
{
private:
    T sum;

public:
    Acumulator() : sum(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    Acumulator(T initial) : sum(initial) {
        std::cout << "Constructor with initial value called" << std::endl;
    }                 
    Acumulator(const Acumulator &other) : sum(other.sum) {
        std::cout << "Copy constructor called" << std::endl;
    } 

    Acumulator &operator=(const Acumulator &other) 
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
        {
            sum = other.sum;
        }
        return *this;
    }
    Acumulator &operator=(const T &value) 
    {
        std::cout << "Assignment operator called" << std::endl;
        sum = value;
        return *this;
    }
    Acumulator &operator+=(const Acumulator &other)
    {
        std::cout << "+= operator called" << std::endl;
        sum += other.sum;
        return *this;
    }
    Acumulator &operator+=(const T &value)
    {
        std::cout << "+= operator called with value" << std::endl;
        sum += value;
        return *this;
    }

    Acumulator& operator+(const Acumulator &other)
    {
        std::cout << "+ operator called with class" << std::endl;
        sum += other.sum;
        return *this;
    }


    friend Acumulator& operator+(const T &value, Acumulator &acc)
    {
        std::cout << "Friend + operator called" << std::endl;
        acc.sum += value;
        return acc;
    }

    friend std::ostream &operator<<(std::ostream &os, const Acumulator &acc)
    {
        return os << "Total Acc: " << acc.sum << std::endl;
    }
};
