#include <iostream>
#include <string>

/*
    This example demonstrates both implicit and explicit type conversions in C++.
    Implicit conversions (also known as type coercion) happen automatically when the compiler converts one type to another.
    Explicit conversions (also known as type casting) require the developer to specify the conversion explicitly.

    Pointer conversions are a specific type of explicit conversion where pointers are cast from one type to another.
    Common use cases include:
    1. Converting a `void*` pointer to a specific type.
    2. Casting between base and derived class pointers in polymorphism.
    3. Reinterpreting memory as a different type using `reinterpret_cast`.
*/

// Preparation for the example
enum Color
{
    Red,
    Green,
    Blue
}; // Enum for demonstration

class Base
{
public:
    virtual void display() const { std::cout << "Base class\n"; }
};

class Derived : public Base
{
public:
    void display() const override { std::cout << "Derived class\n"; }
};

class MyClass
{
    int value;

public:
    MyClass(int v) : value(v) {}           // Constructor allows implicit conversion from int to MyClass
    operator int() const { return value; } // Conversion operator allows implicit conversion from MyClass to int
};

class ExplicitClass
{
    int value;

public:
    explicit ExplicitClass(int v) : value(v) {} // Prevents implicit conversion
    int getValue() const { return value; }
};

void overloadedFunction(int x)
{
    std::cout << "Called overloadedFunction(int): " << x << "\n";
}

void overloadedFunction(double x)
{
    std::cout << "Called overloadedFunction(double): " << x << "\n";
}

int main()
{
    // Implicit Conversion Example
    std::cout << "=== Implicit Conversion ===\n";
    int intVar = 42;
    double doubleVar = intVar; // Implicitly converts int to double
    std::cout << "Integer value: " << intVar << "\n";
    std::cout << "Converted to double: " << doubleVar << "\n";

    char charVar = 'A';
    int asciiValue = charVar; // Implicitly converts char to int (ASCII value)
    std::cout << "Character: " << charVar << "\n";
    std::cout << "Implicitly converted to ASCII value: " << asciiValue << "\n";

    // Explicit Conversion Example
    std::cout << "\n=== Explicit Conversion ===\n";
    double pi = 3.14159;
    int truncatedPi = static_cast<int>(pi); // Explicitly converts double to int (truncates the decimal part)
    std::cout << "Double value: " << pi << "\n";
    std::cout << "Explicitly converted to int (truncated): " << truncatedPi << "\n";

    std::string strNumber = "123";
    int parsedNumber = std::stoi(strNumber); // Explicitly converts string to int using std::stoi
    std::cout << "String value: " << strNumber << "\n";
    std::cout << "Explicitly converted to int: " << parsedNumber << "\n";

    // C-style cast (not recommended, but shown for completeness)
    double largeDouble = 123.456;
    int cStyleCast = (int)largeDouble; // C-style cast
    std::cout << "C-style cast from double to int: " << cStyleCast << "\n";

    // Additional Explicit Conversion Examples
    std::cout << "\n=== Additional Explicit Conversion Examples ===\n";

    // Enum to Integer Conversion
    Color color = Green;
    int colorValue = static_cast<int>(color); // Explicitly convert enum to int
    std::cout << "Enum to Integer Conversion: Green = " << colorValue << "\n";

    // Integer to Enum Conversion
    int intColor = 2;
    Color blueColor = static_cast<Color>(intColor); // Explicitly convert int to enum
    std::cout << "Integer to Enum Conversion: 2 = " << blueColor << "\n";

    // Integer to Floating-Point Conversion
    int wholeNumber = 7;
    double floatingPoint = static_cast<double>(wholeNumber); // Explicitly convert int to double
    std::cout << "Integer to Floating-Point Conversion: " << wholeNumber << " -> " << floatingPoint << "\n";

    // Reference Conversion
    double doubleValue = 42.42;
    const double &constRef = doubleValue;                 // Create a const reference
    double &nonConstRef = const_cast<double &>(constRef); // Explicitly remove constness
    nonConstRef = 50.50;                                  // Modify the value
    std::cout << "Reference Conversion: Modified value = " << doubleValue << "\n";

    // Pointer Conversion Examples
    std::cout << "\n=== Pointer Conversion Examples ===\n";

    // 1. Void Pointer Conversion
    int intValue = 10;
    void *voidPtr = &intValue;                 // Void pointer
    int *intPtr = static_cast<int *>(voidPtr); // Explicitly convert void* to int*
    std::cout << "Void Pointer Conversion: Value pointed by intPtr = " << *intPtr << "\n";

    // 2. Polymorphism: Base to Derived Pointer Conversion
    Derived derivedObj;
    Base *basePtr = &derivedObj;                           // Implicitly convert Derived* to Base*
    Derived *derivedPtr = static_cast<Derived *>(basePtr); // Explicitly convert Base* to Derived*
    derivedPtr->display();           
    
    // 3. Reinterpreting Memory
    long longValue = 123456789;
    int *reinterpretPtr = reinterpret_cast<int *>(&longValue); // Reinterpret long* as int*
    std::cout << "Reinterpreted Memory: First 4 bytes of longValue as int = " << *reinterpretPtr << "\n";

    // 4. Invalid Pointer Conversion (Demonstration Only)
    // This is unsafe and should be avoided in real-world code.
    doubleValue = 42.42;
    int *invalidPtr = reinterpret_cast<int *>(&doubleValue); // Reinterpret double* as int*
    std::cout << "Invalid Pointer Conversion: Interpreting double as int = " << *invalidPtr << "\n";

    // Casting Away Constness Example
    std::cout << "\n=== Casting Away Constness ===\n";
    const int constValue = 100;                         // Constant integer
    int &nonConstValue = const_cast<int &>(constValue); // Cast away constness
    nonConstValue = 200;                                // Modify the value
    std::cout << "Original const value (after modification): " << constValue << "\n";

    // Implicit Conversion to and from Class
    std::cout << "\n=== Implicit Conversion to and from Class ===\n";

    MyClass obj = 42; // Implicitly converts int to MyClass using the constructor
    std::cout << "Implicitly converted int to MyClass: obj = " << static_cast<int>(obj) << "\n";

    int intValue2 = obj; // Implicitly converts MyClass to int using the conversion operator
    std::cout << "Implicitly converted MyClass to int: intValue = " << intValue2 << "\n";

    // Implicit Conversion in Function Overloading
    std::cout << "\n=== Implicit Conversion in Function Overloading ===\n";
    overloadedFunction(42);   // Matches int version
    overloadedFunction(3.14); // Matches double version
    overloadedFunction('A');  // Implicitly converts char to int, matches int version

    // Explicit Keyword for Constructors
    std::cout << "\n=== Explicit Keyword for Constructors ===\n";
    ExplicitClass explicitObj(10); // Allowed because it's explicit and uses constructor
    // ExplicitClass implicitObj = 10; // Error: Implicit conversion is not allowed
    std::cout << "ExplicitClass value: " << explicitObj.getValue() << "\n";

    // Dynamic Casting
    std::cout << "\n=== Dynamic Casting ===\n";
    Base *basePtrDynamic = new Derived();                                 // Renamed to avoid redefinition
    Derived *derivedPtrDynamic = dynamic_cast<Derived *>(basePtrDynamic); // Renamed to avoid redefinition
    if (derivedPtrDynamic)
    {
        derivedPtrDynamic->display(); // Calls Derived's display method
    }
    else
    {
        std::cout << "Dynamic cast failed.\n";
    }

    Base *invalidBasePtr = new Base();                                    // Base pointer pointing to Base object
    Derived *invalidDerivedPtr = dynamic_cast<Derived *>(invalidBasePtr); // Fails
    if (invalidDerivedPtr)
    {
        invalidDerivedPtr->display();
    }
    else
    {
        std::cout << "Dynamic cast failed for invalidBasePtr.\n";
    }

    delete basePtrDynamic;
    delete invalidBasePtr;

    return 0;
}

/*
=== Implicit Conversion ===
Integer value: 42
Converted to double: 42
Character: A
Implicitly converted to ASCII value: 65

=== Explicit Conversion ===
Double value: 3.14159
Explicitly converted to int (truncated): 3
String value: 123
Explicitly converted to int: 123
C-style cast from double to int: 123
=== Additional Explicit Conversion Examples ===
Enum to Integer Conversion: Green = 1
Integer to Enum Conversion: 2 = 2
Integer to Floating-Point Conversion: 7 -> 7
Reference Conversion: Modified value = 50.5
=== Pointer Conversion Examples ===
Void Pointer Conversion: Value pointed by intPtr = 10
Derived class
Reinterpreted Memory: First 4 bytes of longValue as int = 123456789
Invalid Pointer Conversion: Interpreting double as int = -1889785610
=== Casting Away Constness ===
Original const value (after modification): 100
=== Implicit Conversion to and from Class ===
Implicitly converted int to MyClass: obj = 42
Implicitly converted MyClass to int: intValue = 42
=== Implicit Conversion in Function Overloading ===
Called overloadedFunction(int): 42
Called overloadedFunction(double): 3.14
Called overloadedFunction(int): 65
=== Explicit Keyword for Constructors ===
ExplicitClass value: 10
=== Dynamic Casting ===
Derived class
Dynamic cast failed for invalidBasePtr.
*/
