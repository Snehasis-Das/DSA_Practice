/*
    File: 08_insertion_sort.cpp

    Reason for this file:
    ---------------------
    This file implements Insertion Sort.

    Insertion Sort builds the sorted array one element
    at a time by inserting elements into their correct
    position in the already sorted portion.

    It is adaptive and performs very well on nearly
    sorted arrays.
*/

#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of the sorted part to the right
        // until correct position for key is found
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {12, 11, 13, 5, 6};

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
