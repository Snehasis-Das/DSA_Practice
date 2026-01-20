/*
    File: 10_quick_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Quick Sort using the partitioning
    approach.

    Quick Sort is an in-place sorting algorithm with an
    average time complexity of O(n log n). It is widely
    used due to its excellent practical performance.

    This file focuses on understanding partition logic.
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition function (Lomuto partition scheme)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
