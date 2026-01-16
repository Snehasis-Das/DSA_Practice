/*
    File: 03_sliding_window_fixed.cpp

    Reason for this file:
    ---------------------
    This file implements the fixed-size sliding window pattern.

    Fixed window problems involve subarrays of a given size k.
    Sliding window avoids recomputing the sum for each window
    and reduces time complexity from O(n*k) to O(n).

    This pattern is extremely common in interview questions.
*/

#include <iostream>
#include <vector>
using namespace std;

// Find maximum sum of any subarray of size k
int maxSumSubarrayOfSizeK(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1;

    int windowSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        // add current element to window
        windowSum += arr[i];

        // once window reaches size k
        if (i >= k - 1) {
            maxSum = max(maxSum, windowSum);

            // remove the element going out of window
            windowSum -= arr[i - k + 1];
        }
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Max sum of subarray of size "
         << k << " is "
         << maxSumSubarrayOfSizeK(arr, k) << "\n";

    return 0;
}
