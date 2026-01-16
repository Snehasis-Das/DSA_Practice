/*
    File: 01_pass_by_value_vs_reference.cpp

    Reason for this file:
    ---------------------
    This file demonstrates the difference between:
    1. Passing arguments by value (copying data)
    2. Passing arguments by reference (no copy, modifiable)
    3. Passing arguments by const reference (no copy, read-only)

    Understanding this is critical because:
    - Accidental copies can make O(n) operations invisible
    - References improve performance
    - const references prevent accidental modification

    Most STL-based bugs and performance issues come from
    misunderstanding this concept.
*/

#include <iostream>
#include <vector>
using namespace std;

// Pass by value: creates a full copy of the vector
void passByValue(vector<int> v) {
    v[0] = 100;   // modifies local copy only
}

// Pass by reference: no copy, original is modified
void passByReference(vector<int>& v) {
    v[0] = 200;
}

// Pass by const reference: no copy, cannot modify
void passByConstReference(const vector<int>& v) {
    //v[0] = 300; // ❌ compile-time error (uncomment to see)
    cout << "First element (read-only): " << v[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> data = {1, 2, 3, 4, 5};

    cout << "Original: " << data[0] << "\n";

    passByValue(data);
    cout << "After passByValue: " << data[0] << "\n";

    passByReference(data);
    cout << "After passByReference: " << data[0] << "\n";

    passByConstReference(data);

    return 0;
}
