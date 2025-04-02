#include <iostream>

int main() {
    int number = 10;

    // if-else statement
    if (number > 5) {
        std::cout << "Number is greater than 5.\n";
    } else {
        std::cout << "Number is 5 or less.\n";
    }

    // switch statement
    switch (number) {
        case 10:
            std::cout << "Number is exactly 10.\n";
            break;
        case 5:
            std::cout << "Number is exactly 5.\n";
            break;
        default:
            std::cout << "Number is neither 5 nor 10.\n";
            break;
    }

    // for loop
    for (int i = 0; i < 5; ++i) {
        std::cout << "For loop iteration: " << i << "\n";
    }

    // while loop
    int count = 0;
    while (count < 3) {
        std::cout << "While loop count: " << count << "\n";
        ++count;
    }

    // do-while loop
    int doCount = 0;
    do {
        std::cout << "Do-while loop count: " << doCount << "\n";
        ++doCount;
    } while (doCount < 3);

    // goto statement
    int gotoCount = 0;
label:
    if (gotoCount < 2) {
        std::cout << "Goto loop count: " << gotoCount << "\n";
        ++gotoCount;
        goto label; // Jump back to the label
    }

    return 0;
}