/*
    File: 02_lower_and_upper_bound.cpp

    Reason for this file:
    ---------------------
    This file re-implements lower_bound and upper_bound
    using binary search.

    Understanding these functions is critical for solving
    range queries and frequency-related problems on sorted arrays.
*/

#include <iostream>
#include <vector>
using namespace std;

// First index with value >= target
int lowerBound(const vector<int>& arr, int target) {
    int low = 0, high = arr.size(); // note: high = n
    int ans = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid; // move left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// First index with value > target
int upperBound(const vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    int ans = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid; // move left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    cout << "Lower bound of " << x << ": " << lowerBound(arr, x) << "\n";
    cout << "Upper bound of " << x << ": " << upperBound(arr, x) << "\n";

    // Frequency of x
    cout << "Frequency of " << x << ": "
         << upperBound(arr, x) - lowerBound(arr, x) << "\n";

    return 0;
}
