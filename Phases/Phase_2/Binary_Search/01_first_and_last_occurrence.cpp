/*
    File: 01_first_and_last_occurrence.cpp

    Reason for this file:
    ---------------------
    This file finds the first and last occurrence of a target
    in a sorted array using binary search.

    Handling duplicates correctly is a critical interview skill
    and forms the basis for range queries.
*/

#include <iostream>
#include <vector>
using namespace std;

// Find first occurrence of target
int firstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1; // search left
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Find last occurrence of target
int lastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1; // search right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    cout << "First occurrence: " << firstOccurrence(arr, target) << "\n";
    cout << "Last occurrence: " << lastOccurrence(arr, target) << "\n";

    return 0;
}
