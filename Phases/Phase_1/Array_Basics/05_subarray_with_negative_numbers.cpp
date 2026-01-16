/*
    File: 05_subarray_with_negative_numbers.cpp

    Reason for this file:
    ---------------------
    Sliding window techniques fail when the array contains
    negative numbers because the window sum is no longer
    monotonic.

    This file demonstrates the correct approach using:
    - Prefix sums
    - Hash maps

    This pattern is essential for handling subarray problems
    involving negative numbers.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find length of longest subarray with sum <= target
// Works with negative numbers
int longestSubarrayWithSumAtMostK(const vector<int>& arr, int target) {
    int n = arr.size();

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Map prefix sum -> earliest index
    unordered_map<long long, int> firstSeen;
    int maxLen = 0;

    for (int i = 0; i <= n; i++) {
        // Store earliest occurrence of prefix sum
        if (!firstSeen.count(prefix[i])) {
            firstSeen[prefix[i]] = i;
        }

        // We want prefix[i] - prefix[j] <= target
        // => prefix[j] >= prefix[i] - target
        for (auto& [ps, idx] : firstSeen) {
            if (ps >= prefix[i] - target) {
                maxLen = max(maxLen, i - idx);
            }
        }
    }

    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, -1, 2, -3, 4, -2, 1};
    int target = 3;

    cout << "Longest subarray length with sum <= "
         << target << " is "
         << longestSubarrayWithSumAtMostK(arr, target) << "\n";

    return 0;
}
