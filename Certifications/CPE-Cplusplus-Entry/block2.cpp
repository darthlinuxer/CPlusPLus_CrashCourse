#include <iostream>
using namespace std;

// Function declaration
int square(int x) {
    return x * x;
}

// Recursive function
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    // if-else
    int num = 5;
    if (num % 2 == 0)
        cout << "Even\n";
    else
        cout << "Odd\n";

    // Loops
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        cout << "For loop i: " << i << endl;
    }

    // while loop
    int count = 0;
    while (count < 2) {
        cout << "While loop count: " << count << endl;
        count++;
    }

    // do-while loop
    int j = 0;
    do {
        cout << "Do-while j: " << j << endl;
        j++;
    } while (j < 1);

    // Switch
    int val = 2;
    switch (val) {
        case 1: cout << "One\n"; break;
        case 2: cout << "Two\n"; break;
        default: cout << "Other\n"; break;
    }

    // Functions
    cout << "Square of 4: " << square(4) << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    return 0;
}
// Output:
/*
Odd
For loop i: 0
For loop i: 2
While loop count: 0
While loop count: 1
Do-while j: 0
Two
Square of 4: 16
Factorial of 5: 120
*/
