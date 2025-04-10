#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, std::string> myTuple(1, "Hi");
    std::cout << "Tuple: " << std::get<0>(myTuple) << ", " << std::get<1>(myTuple) << "\n";

    return 0;
}

/*
Expected Output:
Tuple: 1, Hi
*/