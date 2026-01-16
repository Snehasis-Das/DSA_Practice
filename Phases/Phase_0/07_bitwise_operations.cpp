/*
    File: 07_bitwise_operations.cpp

    Reason for this file:
    ---------------------
    This file introduces bitwise operations and common bit tricks.

    Bitwise operations allow solving certain problems in O(1)
    that would otherwise take O(n). They are especially useful
    in XOR-based problems and state manipulation.

    Mastery of this file removes fear of low-level operations.
*/

#include <iostream>
using namespace std;

// Check if a number is odd
bool isOdd(int x) {
    return x & 1;
}

// Set the i-th bit
int setBit(int x, int i) {
    return x | (1 << i);
}

// Clear the i-th bit
int clearBit(int x, int i) {
    return x & ~(1 << i);
}

// Toggle the i-th bit
int toggleBit(int x, int i) {
    return x ^ (1 << i);
}

// Count set bits (naive)
int countSetBits(int x) {
    int count = 0;
    while (x > 0) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x = 10; // 1010

    cout << "Is odd: " << isOdd(x) << "\n";
    cout << "Set bit 0: " << setBit(x, 0) << "\n";
    cout << "Clear bit 1: " << clearBit(x, 1) << "\n";
    cout << "Toggle bit 3: " << toggleBit(x, 3) << "\n";
    cout << "Count set bits: " << countSetBits(x) << "\n";

    return 0;
}
