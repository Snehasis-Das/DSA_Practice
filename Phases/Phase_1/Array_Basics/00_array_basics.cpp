/*
    File: 00_array_basics.cpp

    Reason for this file:
    ---------------------
    This file builds fundamental confidence with array manipulation.

    Arrays are the foundation of most DSA problems.
    Before applying advanced techniques (sliding window,
    prefix sums, two pointers), one must be completely
    comfortable with basic array operations.

    This file focuses on:
    - In-place array reversal
    - Finding minimum and maximum elements
    - Clean traversal patterns without STL shortcuts
*/

#include <iostream>
#include <vector>
using namespace std;

// Reverse an array in-place
void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Find minimum element in array
int findMin(const vector<int>& arr) {
    int mn = arr[0];
    for (int x : arr) {
        mn = min(mn, x);
    }
    return mn;
}

// Find maximum element in array
int findMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int x : arr) {
        mx = max(mx, x);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {5, 2, 9, 1, 7};

    reverseArray(arr);

    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Min element: " << findMin(arr) << "\n";
    cout << "Max element: " << findMax(arr) << "\n";

    return 0;
}
