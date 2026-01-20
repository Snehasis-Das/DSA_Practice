/*
    File: 07_selection_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Selection Sort.

    Selection Sort repeatedly selects the minimum element
    from the unsorted portion and places it at the beginning.

    Although its time complexity is O(n^2), it performs
    fewer swaps than Bubble Sort and helps in understanding
    selection-based algorithms.
*/

#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find index of minimum element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Place minimum element at correct position
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {64, 25, 12, 22, 11};

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
