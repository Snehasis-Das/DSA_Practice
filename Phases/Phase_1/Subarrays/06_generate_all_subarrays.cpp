/*
    File: 06_generate_all_subarrays.cpp

    Reason for this file:
    ---------------------
    This file demonstrates how to generate all subarrays
    of a given array.

    Subarrays are contiguous parts of an array.
    Understanding how they are generated using indices
    is essential before learning optimized techniques
    like prefix sums, Kadane's algorithm, or hashing.

    This file builds raw subarray intuition.
*/

#include <iostream>
#include <vector>
using namespace std;

// Generate and print all subarrays
void generateSubarrays(const vector<int>& arr) {
    int n = arr.size();

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            // subarray from start to end
            cout << "[ ";
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << "]\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5};

    generateSubarrays(arr);

    return 0;
}
