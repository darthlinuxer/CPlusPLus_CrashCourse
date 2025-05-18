#include <iostream>
#include "Accumulator.h"

int main()
{
    Acumulator<int> intAcc; // Default constructor called
    intAcc = 1; // Assignment operator called
    intAcc += 5; // += operator called
    intAcc += 10; // += operator called
    Acumulator<int> intAcc2(intAcc); // Copy constructor called
    std::cout << intAcc2;
    Acumulator<int> intAcc3 = intAcc2; // Copy constructor called
    std::cout << intAcc3; 

    Acumulator<double> doubleAcc(3.5); // Constructor with initial value called
    doubleAcc += 2.5; // += operator called
    std::cout << doubleAcc;

    Acumulator<std::string> strAcc("Hello"); //Constructor with initial value called
    strAcc += ", World!";// += operator called
    std::cout << strAcc;

    intAcc2 = 20; // Assignment operator called
    std::cout << intAcc2;
    intAcc3 = intAcc + intAcc2; // + operator called and Copy assignment operator called
    std::cout << intAcc3; 
    Acumulator<int> intAcc4 = intAcc + 5; // Constructor with initial value called, + operator called, Copy constructor called
    std::cout << intAcc4; 
    Acumulator<int> intAcc5 = 5 + intAcc; // Friend + operator called and Constructor with initial value called
    std::cout << intAcc5; 
    Acumulator<int> intAcc6 = intAcc + intAcc2 + 5;  // Constructor with initial value called, + operator called, + operator called, Copy constructor called
    std::cout << intAcc6; 

    return 0;
}

/* output
Default constructor called
Assignment operator called
+= operator called with value
+= operator called with value
Copy constructor called
Total Acc: 16
Copy constructor called
Total Acc: 16
Constructor with initial value called
+= operator called with value
Total Acc: 6
Constructor with initial value called
+= operator called with value
Total Acc: Hello, World!
Assignment operator called
Total Acc: 20
+ operator called with class
Copy assignment operator called
Total Acc: 36
Constructor with initial value called
+ operator called with class
Copy constructor called
Total Acc: 41
Friend + operator called
Copy constructor called
Total Acc: 46
Constructor with initial value called
+ operator called with class
+ operator called with class
Copy constructor called
Total Acc: 71
*/