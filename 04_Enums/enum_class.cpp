// Comprehensive demonstration of `enum` and `enum class` in C++.

#include <iostream>
#include <type_traits>

// Traditional enum
enum TrafficLight {
    Red,
    Yellow,
    Green
};

// Scoped enum (enum class)
enum class Color : int { // Explicitly specifying the underlying type
    Red = 1,
    Green,
    Blue
};

// Function to demonstrate traditional enum
void printTrafficLight(TrafficLight light) {
    switch (light) {
        case Red:
            std::cout << "Traffic Light is Red.\n";
            break;
        case Yellow:
            std::cout << "Traffic Light is Yellow.\n";
            break;
        case Green:
            std::cout << "Traffic Light is Green.\n";
            break;
    }
}

// Function to demonstrate scoped enum (enum class)
void printColor(Color color) {
    switch (color) {
        case Color::Red:
            std::cout << "Color is Red.\n";
            break;
        case Color::Green:
            std::cout << "Color is Green.\n";
            break;
        case Color::Blue:
            std::cout << "Color is Blue.\n";
            break;
    }
}

// Demonstrating type safety and underlying type
void demonstrateEnumFeatures() {
    // Traditional enums are not type-safe
    TrafficLight light = Red;
    int lightValue = light; // Implicit conversion to int
    std::cout << "TrafficLight as int: " << lightValue << "\n";

    // Scoped enums are type-safe
    Color color = Color::Green;
    // int colorValue = color; // Error: Cannot implicitly convert to int
    int colorValue = static_cast<int>(color); // Explicit cast required
    std::cout << "Color as int: " << colorValue << "\n";

    // Checking underlying type of enum class
    std::cout << "Underlying type of Color: "
              << (std::is_same<std::underlying_type<Color>::type, int>::value ? "int" : "not int")
              << "\n";
}

int main() {
    // Demonstrate traditional enum
    TrafficLight trafficLight = Green;
    printTrafficLight(trafficLight);

    // Demonstrate scoped enum (enum class)
    Color myColor = Color::Blue;
    printColor(myColor);

    // Demonstrate additional features of enums
    demonstrateEnumFeatures();

    return 0;
}