/*
    File: 00_fast_io_and_setup.cpp

    Reason for this file:
    ---------------------
    This file sets up a fast and reliable C++ I/O environment.

    In competitive programming and interviews, programs often need to
    process large inputs quickly. By default, C++ streams (cin/cout)
    are synchronized with C I/O (scanf/printf), which makes them slower.

    This file demonstrates:
    1. How to disable synchronization for faster input/output
    2. Why cin and cout should be untied
    3. A clean template that will be reused in all future DSA files

    Mastering this file ensures that performance issues never come
    from input/output, only from algorithmic complexity.
*/

#include <iostream>
using namespace std;

int main() {
    // Disable synchronization between C and C++ I/O
    ios::sync_with_stdio(false);

    // Untie cin from cout to avoid unnecessary flushes
    cin.tie(nullptr);

    // Simple test: read numbers and compute sum
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << sum << "\n";

    return 0;
}
