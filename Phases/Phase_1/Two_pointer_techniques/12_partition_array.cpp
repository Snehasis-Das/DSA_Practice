/*
    File: 12_partition_array.cpp

    Reason for this file:
    ---------------------
    This file demonstrates array partitioning using
    the two-pointer technique.

    Partitioning rearranges elements based on conditions
    without using extra space.

    This concept appears frequently in interviews and
    sorting-related problems.
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition array into even numbers first, then odd numbers
void partitionOddEven(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] % 2 == 0) {
            left++;
        } else {
            swap(arr[left], arr[right]);
            right--;
        }
    }
}

// Partition binary array (0s and 1s)
void partitionZeroOne(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] == 0) {
            left++;
        } else {
            swap(arr[left], arr[right]);
            right--;
        }
    }
}

// Dutch National Flag: partition 0s, 1s, and 2s
void dutchNationalFlag(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 2, 3, 4, 5, 6};
    partitionOddEven(a);
    cout << "Odd-Even partition: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    vector<int> b = {0, 1, 1, 0, 1, 0};
    partitionZeroOne(b);
    cout << "0-1 partition: ";
    for (int x : b) cout << x << " ";
    cout << "\n";

    vector<int> c = {2, 0, 2, 1, 1, 0};
    dutchNationalFlag(c);
    cout << "0-1-2 partition: ";
    for (int x : c) cout << x << " ";
    cout << "\n";

    return 0;
}
