/*
    File: 18_sliding_window_on_string.cpp

    Reason for this file:
    ---------------------
    This file implements the sliding window technique
    on strings using a frequency map.

    Sliding window on strings is used to solve problems
    involving substrings with constraints on characters.

    This file demonstrates the core reusable template.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Length of longest substring without repeating characters
int longestSubstringWithoutRepeating(const string& s) {
    unordered_map<char, int> freq;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        // Shrink window until valid
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abcabcbb";

    cout << "Longest substring without repeating characters: "
         << longestSubstringWithoutRepeating(s) << "\n";

    return 0;
}
