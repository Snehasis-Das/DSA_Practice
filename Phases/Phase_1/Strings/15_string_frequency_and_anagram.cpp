/*
    File: 15_string_frequency_and_anagram.cpp

    Reason for this file:
    ---------------------
    This file demonstrates character frequency counting
    and anagram checking.

    Many string problems rely on counting how many times
    each character appears. Anagram checking is a direct
    and common application of this idea.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Count frequency of lowercase English letters
vector<int> charFrequency(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    return freq;
}

// Check if two strings are anagrams
bool areAnagrams(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;

    vector<int> freq(26, 0);

    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    for (int count : freq) {
        if (count != 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "listen";
    string s2 = "silent";
    string s3 = "hello";

    cout << s1 << " & " << s2 << " -> "
         << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << "\n";

    cout << s1 << " & " << s3 << " -> "
         << (areAnagrams(s1, s3) ? "Anagrams" : "Not Anagrams") << "\n";

    return 0;
}
