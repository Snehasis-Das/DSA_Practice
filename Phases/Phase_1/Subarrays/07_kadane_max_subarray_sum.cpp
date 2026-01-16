/*
    File: 07_kadane_max_subarray_sum.cpp

    Reason for this file:
    ---------------------
    This file implements Kadane's Algorithm to find the
    maximum subarray sum in linear time.

    Kadane's algorithm is a classic example of greedy thinking:
    if the current subarray sum becomes negative, it is better
    to start fresh from the next element.

    This algorithm is frequently asked in interviews and
    forms the basis for many advanced problems.
*/

#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm
int maxSubarraySum(const vector<int>& arr) {
    int maxSoFar = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        // Either extend the current subarray or start new
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSoFar = max(maxSoFar, currentSum);
    }

    return maxSoFar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {-2, 1, -3, 4};

    cout << "Maximum subarray sum: "
         << maxSubarraySum(arr) << "\n";

    return 0;
}
