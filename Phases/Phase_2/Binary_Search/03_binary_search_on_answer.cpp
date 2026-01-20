/*
    File: 03_binary_search_on_answer.cpp

    Reason for this file:
    ---------------------
    This file demonstrates binary search on the answer space.

    Instead of searching within an array, we search for the
    minimum value that satisfies a given condition.

    This pattern is extremely common in optimization problems
    asked during interviews.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Check if we can split array into <= k subarrays
// such that maximum subarray sum <= maxAllowed
bool canSplit(const vector<int>& arr, int k, int maxAllowed) {
    int subarrays = 1;
    int currentSum = 0;

    for (int x : arr) {
        if (x > maxAllowed) return false;

        if (currentSum + x <= maxAllowed) {
            currentSum += x;
        } else {
            subarrays++;
            currentSum = x;
        }
    }

    return subarrays <= k;
}

// Find minimum possible maximum subarray sum
int minimizeMaximumSubarraySum(const vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(arr, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller answer
        } else {
            low = mid + 1;  // need larger answer
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "Minimum possible maximum subarray sum: "
         << minimizeMaximumSubarraySum(arr, k) << "\n";

    return 0;
}
