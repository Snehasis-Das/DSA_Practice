/*
    File: 13_reverse_string.cpp

    Reason for this file:
    ---------------------
    This file implements in-place string reversal using
    the two-pointer technique.

    String reversal is a foundational operation that
    appears directly or indirectly in many string problems.

    Mastering this builds confidence with character-level
    manipulation.
*/

#include <iostream>
#include <string>
using namespace std;

// Reverse a string in-place
void reverseString(string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "hello";

    reverseString(s);

    cout << "Reversed string: " << s << "\n";

    return 0;
}
