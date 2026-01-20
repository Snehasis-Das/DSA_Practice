/*
    File: 05_peak_element.cpp

    Reason for this file:
    ---------------------
    This file finds a peak element using binary search.

    A peak element is an element that is greater than
    its immediate neighbors.

    This problem demonstrates that binary search can
    be applied even when the array is not globally sorted,
    as long as a local monotonic property exists.
*/

#include <iostream>
#include <vector>
using namespace std;

// Find index of a peak element
int findPeakElement(const vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Peak lies on the right
            low = mid + 1;
        } else {
            // Peak lies on the left or at mid
            high = mid;
        }
    }

    return low; // low == high, pointing to a peak
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};

    int peakIndex = findPeakElement(arr);

    cout << "Peak element found at index: " << peakIndex
         << ", value: " << arr[peakIndex] << "\n";

    return 0;
}
