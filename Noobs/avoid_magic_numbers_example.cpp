// This file demonstrates the importance of avoiding magic numbers in code.
// Why this is the right way:
// - It uses named constants, making the code more readable and maintainable.
// - It reduces the risk of errors caused by hardcoding values.
// How a noob might do it:
// - A noob might use hardcoded values (magic numbers) directly in the code, making it harder to understand and maintain.

#include <iostream>

// Demonstrating the use of named constants instead of magic numbers
float calculateEnergy(float mass) {
    constexpr float SPEED_OF_LIGHT = 299792458.0f; // Speed of light in meters per second
    return mass * SPEED_OF_LIGHT * SPEED_OF_LIGHT;
}

int main() {
    float mass = 1.0f; // Mass in kilograms
    float energy = calculateEnergy(mass);
    std::cout << "Energy: " << energy << " joules" << std::endl;
    return 0;
}

/* Expected Output:
Energy: 8.98755e+16 joules
*/