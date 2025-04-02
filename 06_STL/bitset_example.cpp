#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> bits(42); // Binary representation of 42 (00101010)

    std::cout << "Bitset: " << bits << "\n"; // Print the bitset
    std::cout << "Number of set bits: " << bits.count() << "\n"; // Count 1s in the bitset

    bits.set(0); // Set the 0th bit to 1
    std::cout << "After setting 0th bit: " << bits << "\n";

    bits.flip(); // Flip all bits
    std::cout << "After flipping: " << bits << "\n";

    return 0;
}

/*
Expected Output:
Bitset: 00101010
Number of set bits: 3
After setting 0th bit: 00101011
After flipping: 11010100
*/