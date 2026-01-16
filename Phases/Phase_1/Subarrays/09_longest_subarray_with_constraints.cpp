/*
    File: 09_longest_subarray_with_constraints.cpp

    Reason for this file:
    ---------------------
    This file finds the longest subarray satisfying a constraint
    using prefix sums and a hash map.

    Unlike counting subarrays, this problem focuses on maximizing
    length, so we store the earliest occurrence of a prefix sum.

    This pattern is widely used in interview problems.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Longest subarray with sum exactly equal to target
int longestSubarrayWithSumK(const vector<int>& arr, int target) {
    unordered_map<int, int> firstIndex;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // If subarray from 0 to i has sum == target
        if (prefixSum == target) {
            maxLen = i + 1;
        }

        // If prefixSum - target seen before
        if (firstIndex.count(prefixSum - target)) {
            maxLen = max(maxLen, i - firstIndex[prefixSum - target]);
        }

        // Store earliest occurrence only
        if (!firstIndex.count(prefixSum)) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, -1, 5, -2, 3};
    int target = 3;

    cout << "Longest subarray length with sum "
         << target << " is "
         << longestSubarrayWithSumK(arr, target) << "\n";

    return 0;
}
