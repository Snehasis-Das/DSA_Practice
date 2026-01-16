/*
    File: 02_const_correctness.cpp

    Reason for this file:
    ---------------------
    This file teaches const correctness in C++.

    const is used to:
    - Prevent accidental modification
    - Make function intent explicit
    - Enable safer APIs
    - Improve readability and maintainability

    Interviewers often judge C++ maturity by
    how naturally a candidate uses const.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function that promises NOT to modify input
int sumVector(const vector<int>& v) {
    int sum = 0;
    for (int x : v) {
        sum += x;
    }
    return sum;
}

// Example class to demonstrate const member functions
class Box {
    int value;

public:
    Box(int v) : value(v) {}

    // Can modify object
    void setValue(int v) {
        value = v;
    }

    // Cannot modify object
    int getValue() const {
        return value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int a = 10;
    // a = 20; // ❌ error: cannot modify const variable

    int b = 5;

    // Pointer to const int (data cannot be changed)
    const int* p1 = &b;
    // *p1 = 10; // ❌ not allowed

    // Const pointer to int (pointer cannot change)
    int* const p2 = &b;
    *p2 = 20; // allowed

    // Const pointer to const int
    const int* const p3 = &b;
    // *p3 = 30; // ❌
    // p3 = &a;  // ❌

    vector<int> nums = {1, 2, 3, 4};

    cout << "Sum: " << sumVector(nums) << "\n";

    Box box(100);
    cout << "Box value: " << box.getValue() << "\n";

    return 0;
}
