/*
    File: 11_counting_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Counting Sort, a non-comparison
    sorting algorithm.

    Counting Sort is efficient when the input consists
    of integers within a small known range.

    It demonstrates how sorting can be done using
    frequency counting instead of comparisons.
*/

#include <iostream>
#include <vector>
using namespace std;

// Counting Sort for non-negative integers
void countingSort(vector<int>& arr, int maxValue) {
    int n = arr.size();

    // Frequency array
    vector<int> count(maxValue + 1, 0);

    // Count occurrences
    for (int x : arr) {
        count[x]++;
    }

    // Reconstruct sorted array
    int index = 0;
    for (int value = 0; value <= maxValue; value++) {
        while (count[value] > 0) {
            arr[index++] = value;
            count[value]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    int maxValue = 8;

    countingSort(arr, maxValue);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
