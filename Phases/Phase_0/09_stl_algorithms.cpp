/*
    File: 09_stl_algorithms.cpp

    Reason for this file:
    ---------------------
    This file introduces commonly used STL algorithms.

    STL algorithms:
    - Reduce code length
    - Reduce bugs
    - Improve readability
    - Are optimized and well-tested

    Interviewers expect familiarity with these tools.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {5, 1, 4, 2, 2, 3};

    // sort
    sort(v.begin(), v.end());

    // reverse
    reverse(v.begin(), v.end());

    cout << "After sort + reverse: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // find
    auto it = find(v.begin(), v.end(), 2);
    if (it != v.end()) {
        cout << "Found 2 at index: " << (it - v.begin()) << "\n";
    }

    // count
    cout << "Count of 2: " << count(v.begin(), v.end(), 2) << "\n";

    // lower_bound & upper_bound (requires sorted order)
    sort(v.begin(), v.end());
    int L = 2, R = 4;

    auto lb = lower_bound(v.begin(), v.end(), L);
    auto ub = upper_bound(v.begin(), v.end(), R);

    cout << "Elements in range [2,4): " << (ub - lb) << "\n";

    // accumulate
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << "\n";

    // min & max
    cout << "Min element: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "Max element: " << *max_element(v.begin(), v.end()) << "\n";

    return 0;
}
