/*
    File: 08_count_subarrays_with_given_sum.cpp

    Reason for this file:
    ---------------------
    This file implements counting subarrays with a given sum
    using prefix sums and a hash map.

    This approach works for:
    - Positive numbers
    - Negative numbers
    - Zero values

    It reduces time complexity from O(n^2) to O(n).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Count subarrays with sum equal to target
int countSubarraysWithSum(const vector<int>& arr, int target) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // base case

    int prefixSum = 0;
    int count = 0;

    for (int x : arr) {
        prefixSum += x;

        // Check if prefixSum - target exists
        if (prefixCount.count(prefixSum - target)) {
            count += prefixCount[prefixSum - target];
        }

        // Record current prefix sum
        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, -2, 5};
    int target = 5;

    cout << "Count of subarrays with sum "
         << target << " is "
         << countSubarraysWithSum(arr, target) << "\n";

    return 0;
}
