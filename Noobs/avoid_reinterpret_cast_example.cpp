// This file demonstrates an alternative to using reinterpret_cast in C++.
// Why this is the right way:
// - It avoids the potential undefined behavior associated with reinterpret_cast.
// - It uses safer alternatives like std::memcpy to achieve the same result.
// How a noob might do it:
// - A noob might use reinterpret_cast without understanding its risks, leading to undefined behavior.

#include <iostream>
#include <iomanip>
#include <cstring>

// Demonstrating an alternative to reinterpret_cast using memcpy
void printBytesAlternative(const float &input) {
    unsigned char bytes[sizeof(float)];
    std::memcpy(bytes, &input, sizeof(float));

    std::cout << "[";
    for (std::size_t i = 0; i < sizeof(float); ++i) {
        if (i != 0) std::cout << " ";
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(bytes[i]);
    }
    std::cout << "]\n";
}

int main() {
    float value = 0.123f;
    printBytesAlternative(value);
    return 0;
}

/* Expected Output:
[3d fc a7 42] (or similar, depending on system endianness)
*/