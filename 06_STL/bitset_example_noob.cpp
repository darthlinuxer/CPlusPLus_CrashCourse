#include <iostream>
#include <string>

std::string toBinary(int num, int bits = 8) {
    std::string binary = "";
    for (int i = bits - 1; i >= 0; --i) {
        binary += (num & (1 << i)) ? '1' : '0';
    }
    return binary;
}

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int bits = 42; // Binary representation of 42 (00101010)

    std::cout << "Bitset: " << toBinary(bits) << "\n"; // Print the bitset
    std::cout << "Number of set bits: " << countSetBits(bits) << "\n"; // Count 1s in the bitset

    bits |= 1; // Set the 0th bit to 1
    std::cout << "After setting 0th bit: " << toBinary(bits) << "\n";

    bits = ~bits & 0xFF; // Flip all bits (limit to 8 bits)
    std::cout << "After flipping: " << toBinary(bits) << "\n";

    return 0;
}

/*
Expected Output:
Bitset: 00101010
Number of set bits: 3
After setting 0th bit: 00101011
After flipping: 11010100
*/