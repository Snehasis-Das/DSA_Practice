/*
    File: 04_iterators_and_range_loops.cpp

    Reason for this file:
    ---------------------
    This file introduces iterators and range-based loops.

    Iterators are the glue between containers and algorithms.
    Understanding them prevents bugs related to erasing elements,
    invalid memory access, and incorrect traversal.

    This file builds confidence in reading and writing
    STL-heavy code used in DSA problems.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {10, 20, 30, 40};

    // ===== Iterator basics =====
    cout << "Using iterators: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // ===== Range-based loop (read-only) =====
    cout << "Range-based (read-only): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

    // ===== Range-based loop (modifiable) =====
    for (int& x : v) {
        x *= 2;
    }

    cout << "After modification: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ===== Erasing with iterators =====
    vector<int> nums = {1, 2, 3, 4, 5};

    for (auto it = nums.begin(); it != nums.end(); ) {
        if (*it % 2 == 0) {
            it = nums.erase(it); // erase returns next valid iterator
        } else {
            ++it;
        }
    }

    cout << "After erasing evens: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}
