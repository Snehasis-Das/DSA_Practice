/*
    File: 01_array_rotation.cpp

    Reason for this file:
    ---------------------
    This file implements array rotation, a very common
    sub-problem in DSA and interviews.

    Array rotation trains:
    - Index arithmetic
    - Modulo reasoning
    - In-place array manipulation

    The reversal technique used here is reusable in
    many other problems.
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper function to reverse part of the array
void reverseRange(vector<int>& arr, int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Rotate array to the right by k steps
void rotateRight(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    k = k % n;  // handle k > n
    if (k == 0) return;

    // Step 1: reverse whole array
    reverseRange(arr, 0, n - 1);

    // Step 2: reverse first k elements
    reverseRange(arr, 0, k - 1);

    // Step 3: reverse remaining elements
    reverseRange(arr, k, n - 1);
}

// Rotate array to the left by k steps
void rotateLeft(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    k = k % n;
    if (k == 0) return;

    // Left rotation by k = Right rotation by (n - k)
    rotateRight(arr, n - k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    rotateRight(arr, 3);
    cout << "Right rotated by 3: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    rotateLeft(arr, 3);
    cout << "Left rotated by 3: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
