/*
    File: 14_check_palindrome.cpp

    Reason for this file:
    ---------------------
    This file checks whether a string is a palindrome
    using the two-pointer technique.

    Palindrome checking is a very common interview
    sub-problem and reinforces clean pointer movement
    and boundary handling.
*/

#include <iostream>
#include <string>
using namespace std;

// Check if a string is a palindrome
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "radar";
    string s2 = "hello";

    cout << s1 << " -> " << (isPalindrome(s1) ? "Palindrome" : "Not Palindrome") << "\n";
    cout << s2 << " -> " << (isPalindrome(s2) ? "Palindrome" : "Not Palindrome") << "\n";

    return 0;
}
