/*
    File: 02_prefix_and_difference_arrays.cpp

    Reason for this file:
    ---------------------
    This file introduces prefix sums and difference arrays.

    These techniques allow:
    - Fast range queries
    - Efficient range updates
    - Elimination of nested loops

    Many array and range-based problems rely directly
    on these two concepts.
*/

#include <iostream>
#include <vector>
using namespace std;

// Build prefix sum array
vector<int> buildPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

// Range sum query using prefix sum
int rangeSum(const vector<int>& prefix, int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

// Build difference array
vector<int> buildDifferenceArray(const vector<int>& arr) {
    int n = arr.size();
    vector<int> diff(n);

    diff[0] = arr[0];
    for (int i = 1; i < n; i++) {
        diff[i] = arr[i] - arr[i - 1];
    }
    return diff;
}

// Apply range update using difference array
void rangeUpdate(vector<int>& diff, int l, int r, int val) {
    diff[l] += val;
    if (r + 1 < diff.size())
        diff[r + 1] -= val;
}

// Recover original array from difference array
vector<int> recoverArray(const vector<int>& diff) {
    int n = diff.size();
    vector<int> arr(n);

    arr[0] = diff[0];
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + diff[i];
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5};

    // Prefix sum demo
    auto prefix = buildPrefixSum(arr);
    cout << "Range sum [1,3]: " << rangeSum(prefix, 1, 3) << "\n";

    // Difference array demo
    auto diff = buildDifferenceArray(arr);

    // Add 10 to range [1,3]
    rangeUpdate(diff, 1, 3, 10);

    auto updatedArr = recoverArray(diff);

    cout << "Array after range update: ";
    for (int x : updatedArr) cout << x << " ";
    cout << "\n";

    return 0;
}
