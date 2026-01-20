/*
    File: 06_bubble_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Bubble Sort to demonstrate the
    simplest comparison-based sorting algorithm.

    Bubble Sort helps in understanding:
    - Adjacent comparisons
    - Swapping logic
    - Why naive sorting algorithms are inefficient

    It also introduces a basic optimization using a swap flag.
*/

#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort with early stopping optimization
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {5, 1, 4, 2, 8};

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
