/*
    File: 12_radix_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Radix Sort using Counting Sort
    as a stable subroutine.

    Radix Sort sorts numbers digit by digit and achieves
    linear time complexity for fixed-width integers.

    This file demonstrates how non-comparison sorting
    can handle large values efficiently.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting sort based on digit represented by exp
void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0); // digits 0–9

    // Count digit occurrences
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert count[] to prefix sum (positions)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (RIGHT TO LEFT for stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(vector<int>& arr) {
    int maxValue = *max_element(arr.begin(), arr.end());

    // Sort by each digit
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
