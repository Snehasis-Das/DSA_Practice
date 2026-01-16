/*
    File: 06_custom_comparators.cpp

    Reason for this file:
    ---------------------
    This file teaches how to define custom ordering logic.

    Many DSA problems require sorting by:
    - Multiple fields
    - Non-natural ordering
    - Priority-based rules

    Understanding comparators ensures full control
    over sorting and heap behavior.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Comparator struct for sorting pairs
struct PairComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;   // tie-breaker
        return a.second < b.second;     // primary sort
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> v = {
        {1, 3}, {2, 2}, {3, 3}, {4, 1}
    };

    // ===== Sort using struct comparator =====
    sort(v.begin(), v.end(), PairComparator());

    cout << "Sorted using struct comparator: ";
    for (auto& p : v) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    // ===== Sort using lambda comparator =====
    sort(v.begin(), v.end(), [](const pair<int, int>& a,
                                const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    cout << "Sorted using lambda comparator: ";
    for (auto& p : v) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    // ===== Priority Queue (Max Heap by default) =====
    priority_queue<pair<int, int>> pq;
    pq.push({1, 3});
    pq.push({2, 2});
    pq.push({3, 1});

    cout << "Default priority_queue top: "
         << "(" << pq.top().first << "," << pq.top().second << ")\n";

    // ===== Priority Queue with custom comparator (Min Heap) =====
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        PairComparator
    > minPQ;

    minPQ.push({1, 3});
    minPQ.push({2, 2});
    minPQ.push({3, 1});

    cout << "Custom priority_queue top: "
         << "(" << minPQ.top().first << "," << minPQ.top().second << ")\n";

    return 0;
}
