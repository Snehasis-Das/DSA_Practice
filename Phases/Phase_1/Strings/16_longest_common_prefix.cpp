/*
    File: 16_longest_common_prefix.cpp

    Reason for this file:
    ---------------------
    This file finds the longest common prefix among
    a list of strings.

    The solution focuses on careful character comparison
    and early termination to avoid unnecessary work.

    This problem strengthens boundary handling and
    string traversal skills.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Find longest common prefix among strings
string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size()
               && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);

        if (prefix.empty())
            return "";
    }

    return prefix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest common prefix: "
         << longestCommonPrefix(strs) << "\n";

    return 0;
}
