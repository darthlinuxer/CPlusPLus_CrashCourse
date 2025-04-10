#include <iostream>
#include <string>

// A template function for adding two values
template <typename T>
T add(T a, T b) {
    return a + b;
}

// A template class for a simple pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 first, T2 second) : first(first), second(second) {}

    void display() const {
        std::cout << "First: " << first << ", Second: " << second << std::endl;
    }
};

int main() {
    std::cout << "Template Function Example:" << std::endl;
    std::cout << "Sum of 3 and 4: " << add(3, 4) << std::endl;
    std::cout << "Sum of 1.5 and 2.5: " << add(1.5, 2.5) << std::endl;

    std::cout << "\nTemplate Class Example:" << std::endl;
    Pair<int, std::string> p(1, "C++");
    p.display();

    return 0;
}
