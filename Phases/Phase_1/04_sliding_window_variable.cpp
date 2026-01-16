/*
    File: 04_sliding_window_variable.cpp

    Reason for this file:
    ---------------------
    This file implements the variable-size sliding window pattern.

    Variable sliding window problems do not have a fixed window size.
    Instead, the window expands and shrinks based on a condition.

    This pattern is heavily used in problems involving:
    - Longest / shortest subarray
    - Constraints (sum, distinct count, frequency)
    - String processing
*/

#include <iostream>
#include <vector>
using namespace std;

// Find the length of the longest subarray
// with sum <= target
int longestSubarrayWithSumAtMostK(const vector<int>& arr, int target) {
    int n = arr.size();

    int left = 0;
    int windowSum = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        // expand window
        windowSum += arr[right];

        // shrink window until valid
        while (windowSum > target) {
            windowSum -= arr[left];
            left++;
        }

        // update answer
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int target = 7;

    cout << "Longest subarray length with sum <= "
         << target << " is "
         << longestSubarrayWithSumAtMostK(arr, target) << "\n";

    return 0;
}
