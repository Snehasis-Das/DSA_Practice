/*
    File: 08_integer_overflow.cpp

    Reason for this file:
    ---------------------
    This file demonstrates integer overflow in C++.

    Integer overflow causes incorrect results without
    any runtime error. Understanding limits and proper
    casting is essential for correct DSA solutions.

    This file trains you to detect and prevent overflow.
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 100000;
    int b = 100000;

    // Overflow happens here
    int wrong = a * b;
    cout << "Overflowed int result: " << wrong << "\n";

    // Correct way
    long long correct = 1LL * a * b;
    cout << "Correct long long result: " << correct << "\n";

    // Integer limits
    cout << "INT_MAX: " << INT_MAX << "\n";
    cout << "LLONG_MAX: " << LLONG_MAX << "\n";

    return 0;
}
