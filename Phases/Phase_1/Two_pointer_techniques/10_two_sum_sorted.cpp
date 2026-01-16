/*
    File: 10_two_sum_sorted.cpp

    Reason for this file:
    ---------------------
    This file implements the two-pointer technique to solve
    the two-sum problem on a sorted array.

    Two pointers eliminate the need for extra space and
    solve the problem in linear time.

    This pattern is foundational for many array problems.
*/

#include <iostream>
#include <vector>
using namespace std;

// Check if there exists a pair with given sum in sorted array
bool twoSumSorted(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;    // need a bigger sum
        else
            right--;  // need a smaller sum
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 6, 8};
    int target = 10;

    cout << (twoSumSorted(arr, target) ? "Found\n" : "Not Found\n");

    return 0;
}
