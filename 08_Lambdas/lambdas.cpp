#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // For std::function

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 1. Basic lambda to print each number.
    auto print = [](int num) { std::cout << num << " "; };
    std::cout << "Numbers: ";
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << "\n";

    // 2. Lambda with capture by reference to calculate the sum of numbers.
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&sum](int num) { sum += num; });
    std::cout << "Sum of numbers: " << sum << "\n";

    // 3. Lambda with capture by value.
    int multiplier = 2;
    auto multiply = [multiplier](int num) { return num * multiplier; };
    std::cout << "Numbers multiplied by " << multiplier << ": ";
    for (int num : numbers) {
        std::cout << multiply(num) << " ";
    }
    std::cout << "\n";

    // 4. Mutable lambda (allows modifying captured variables by value).
    int counter = 0;
    auto increment = [counter]() mutable { return ++counter; };
    std::cout << "Incrementing counter using mutable lambda: ";
    std::cout << increment() << " " << increment() << " " << increment() << "\n";

    // 5. Lambda with explicit return type.
    auto divide = [](double a, double b) -> double {
        if (b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
    };
    std::cout << "Division result (10 / 2): " << divide(10, 2) << "\n";

    // 6. Generic lambda (uses auto for parameters).
    auto genericLambda = [](auto a, auto b) { return a + b; };
    std::cout << "Generic lambda result (5 + 2.5): " << genericLambda(5, 2.5) << "\n";

    // 7. Lambda stored in std::function.
    std::function<int(int, int)> add = [](int a, int b) { return a + b; };
    std::cout << "Lambda stored in std::function (3 + 4): " << add(3, 4) << "\n";

    // 8. Lambda with default capture by reference.
    int x = 10, y = 20;
    auto captureByRef = [&]() { x += y; };
    captureByRef();
    std::cout << "After capture by reference, x: " << x << "\n";

    // 9. Lambda with default capture by value.
    auto captureByValue = [=]() { return x + y; };
    std::cout << "Capture by value result: " << captureByValue() << "\n";

    // 10. Recursive lambda (using std::function).
    std::function<int(int)> factorial = [&](int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };
    std::cout << "Factorial of 5: " << factorial(5) << "\n";

    // 11. Lambda as a predicate for std::find_if.
    auto isEven = [](int num) { return num % 2 == 0; };
    auto evenIt = std::find_if(numbers.begin(), numbers.end(), isEven);
    if (evenIt != numbers.end()) {
        std::cout << "First even number: " << *evenIt << "\n";
    }

    // 12. Capturing everything by value or reference.
    auto captureAllByValue = [=]() { return x + y + sum; };
    auto captureAllByRef = [&]() { x++; y++; sum++; };
    std::cout << "Capture all by value result: " << captureAllByValue() << "\n";
    captureAllByRef();
    std::cout << "After capture all by reference, x: " << x << ", y: " << y << ", sum: " << sum << "\n";

    return 0;
}

/*
Numbers: 1 2 3 4 5 
Sum of numbers: 15
Numbers multiplied by 2: 2 4 6 8 10
Incrementing counter using mutable lambda: 3 2 1
Division result (10 / 2): 5
Generic lambda result (5 + 2.5): 7.5
Lambda stored in std::function (3 + 4): 7
After capture by reference, x: 30
Capture by value result: 50
Factorial of 5: 120
First even number: 2
Capture all by value result: 65
After capture all by reference, x: 31, y: 21, sum: 16
*/