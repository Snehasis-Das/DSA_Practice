/*
    File: 05_lambda_functions.cpp

    Reason for this file:
    ---------------------
    This file introduces lambda functions in C++.

    Lambdas allow writing small, inline functions without
    creating separate named functions. They are heavily used
    in STL algorithms like sort, find_if, and count_if.

    Mastering lambdas makes STL code shorter, clearer,
    and easier to reason about during interviews.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {5, 2, 9, 1, 5, 6};

    // ===== Simple lambda for sorting =====
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b; // ascending
    });

    cout << "Sorted ascending: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ===== Lambda with custom logic =====
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b; // descending
    });

    cout << "Sorted descending: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ===== Using lambda with count_if =====
    int countEven = count_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });

    cout << "Even numbers count: " << countEven << "\n";

    // ===== Lambda capturing variables =====
    int threshold = 4;
    int greaterThanThreshold = count_if(v.begin(), v.end(),
        [threshold](int x) {
            return x > threshold;
        }
    );

    cout << "Greater than threshold: " << greaterThanThreshold << "\n";

    return 0;
}
