/*
    File: 11_remove_duplicates_in_place.cpp

    Reason for this file:
    ---------------------
    This file demonstrates how to remove duplicates from a
    sorted array in-place using the two-pointer technique.

    The key idea is to separate:
    - Reading elements
    - Writing unique elements

    This approach uses O(1) extra space and runs in O(n) time.
*/

#include <iostream>
#include <vector>
using namespace std;

// Remove duplicates in-place from sorted array
// Returns the new length of the array
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;

    int write = 1;  // index to write next unique element

    for (int read = 1; read < arr.size(); read++) {
        if (arr[read] != arr[read - 1]) {
            arr[write] = arr[read];
            write++;
        }
    }

    return write;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4};

    int newLength = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
