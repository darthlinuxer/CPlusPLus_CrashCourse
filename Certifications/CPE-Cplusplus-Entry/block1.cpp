#include <iostream>
using namespace std;

int main() {
    // Built-in types and literals
    int a = 10, b = 3;
    float f = 3.14;
    char c = 'A';
    bool flag = true;

    // Operators
    cout << "Addition: " << a + b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;

    // Increment/Decrement
    cout << "Pre-increment: " << ++a << endl;
    cout << "Post-decrement: " << b-- << endl;

    // Short-circuit
    if (flag && (a > 5)) {
        cout << "Short-circuit AND passed\n";
    }

    // Bitwise
    cout << "Bitwise AND: " << (a & b) << endl;

    // Logical and relational
    cout << "Logical NOT: " << !flag << endl;
    cout << "Relational: " << (a >= b) << endl;

    // Assignment and shortcut
    a += 5;
    cout << "Shortcut assignment: " << a << endl;

    // I/O
    // cout << "Enter a number: ";
    int x = 42; // Default value for automation
    cout << "You entered: " << x << endl;
    return 0;
}
// Output:
/*
Addition: 13
Division: 3
Modulus: 1
Pre-increment: 11
Post-decrement: 3
Short-circuit AND passed
Bitwise AND: 2
Logical NOT: 0
Relational: 1
Shortcut assignment: 16
You entered: 42
*/
