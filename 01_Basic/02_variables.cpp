#include <iostream>
#include <cstdint> // For fixed-width integer types

int main() {
    // Integer types
    int age = 25;
    short shortVar = 10;
    long longVar = 100000L;
    long long longLongVar = 10000000000LL;
    unsigned int unsignedIntVar = 50;
    unsigned long unsignedLongVar = 100000UL;

    // Fixed-width integer types
    std::int8_t int8Var = 127;
    std::int16_t int16Var = 32767;
    std::int32_t int32Var = 2147483647;
    std::int64_t int64Var = 9223372036854775807LL;
    std::uint8_t uint8Var = 255;
    std::uint16_t uint16Var = 65535;
    std::uint32_t uint32Var = 4294967295U;
    std::uint64_t uint64Var = 18446744073709551615ULL;

    // Floating-point types
    float floatVar = 3.14f;
    double height = 5.9;
    long double longDoubleVar = 3.141592653589793238L;

    // Character types
    char grade = 'A';
    wchar_t wideChar = L'B';
    char16_t char16Var = u'C';
    char32_t char32Var = U'D';

    // Boolean type
    bool isStudent = true;

    // Void pointer (demonstration only, typically used for generic pointers)
    void* voidPtr = nullptr;

    // Printing variables
    std::cout << "Age: " << age << "\n";
    std::cout << "Short: " << shortVar << "\n";
    std::cout << "Long: " << longVar << "\n";
    std::cout << "Long Long: " << longLongVar << "\n";
    std::cout << "Unsigned Int: " << unsignedIntVar << "\n";
    std::cout << "Unsigned Long: " << unsignedLongVar << "\n";

    std::cout << "Int8: " << static_cast<int>(int8Var) << "\n";
    std::cout << "Int16: " << int16Var << "\n";
    std::cout << "Int32: " << int32Var << "\n";
    std::cout << "Int64: " << int64Var << "\n";
    std::cout << "UInt8: " << static_cast<unsigned int>(uint8Var) << "\n";
    std::cout << "UInt16: " << uint16Var << "\n";
    std::cout << "UInt32: " << uint32Var << "\n";
    std::cout << "UInt64: " << uint64Var << "\n";

    std::cout << "Float: " << floatVar << "\n";
    std::cout << "Height (Double): " << height << "\n";
    std::cout << "Long Double: " << longDoubleVar << "\n";

    std::cout << "Grade (Char): " << grade << "\n";
    std::wcout << L"Wide Char: " << wideChar << L"\n";
    std::cout << "Char16: " << static_cast<char>(char16Var) << "\n";
    std::cout << "Char32: " << static_cast<char>(char32Var) << "\n";

    std::cout << "Is Student (Bool): " << std::boolalpha << isStudent << "\n";

    return 0;
}