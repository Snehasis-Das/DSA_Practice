/*
    File: 04_binary_search_rotated_array.cpp

    Reason for this file:
    ---------------------
    This file searches for an element in a rotated
    sorted array using binary search.

    The key insight is that at least one half of the
    array is always sorted, which allows us to
    discard half of the search space each step.
*/

#include <iostream>
#include <vector>
using namespace std;

// Search target in rotated sorted array (no duplicates)
int searchRotatedArray(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1; // target in left half
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1; // target in right half
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Target found at index: "
         << searchRotatedArray(arr, target) << "\n";

    return 0;
}
