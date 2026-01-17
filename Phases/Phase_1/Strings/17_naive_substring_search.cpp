/*
    File: 17_naive_substring_search.cpp

    Reason for this file:
    ---------------------
    This file implements naive substring search.

    The naive approach checks for the pattern starting
    at every possible position in the text.

    While not optimal, this method is easy to understand
    and serves as a foundation for advanced algorithms
    like KMP.
*/

#include <iostream>
#include <string>
using namespace std;

// Return true if pattern exists in text
bool containsSubstring(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m > n) return false;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return true; // full match found
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text = "interviewpreparation";
    string pattern = "view";

    cout << (containsSubstring(text, pattern)
             ? "Pattern found\n"
             : "Pattern not found\n");

    return 0;
}
