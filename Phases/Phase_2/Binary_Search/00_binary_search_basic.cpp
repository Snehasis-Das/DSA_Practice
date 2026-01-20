/*
    File: 00_binary_search_basic.cpp

    Reason for this file:
    ---------------------
    This file implements the standard binary search algorithm.

    Binary search works on sorted data and reduces the search
    space by half at every step, achieving O(log n) time.

    This file focuses on:
    - Correct boundary handling
    - Safe mid calculation
    - Clear decision logic

    Every other binary search variant builds on this foundation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Standard binary search
// Returns index of target if found, otherwise -1
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        // Safe mid calculation (prevents overflow)
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;   // target is in right half
        } else {
            high = mid - 1;  // target is in left half
        }
    }

    return -1; // not found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Target found at index " << index << "\n";
    else
        cout << "Target not found\n";

    return 0;
}
