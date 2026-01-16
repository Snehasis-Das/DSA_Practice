/*
    File: 03_stl_containers_basics.cpp

    Reason for this file:
    ---------------------
    This file introduces core STL containers used in DSA problems.

    The goal is NOT memorization, but understanding:
    - What data structure each container represents
    - How insertion, deletion, and lookup behave
    - When each container should be preferred

    Choosing the right STL container often solves
    half the problem instantly.
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ===== VECTOR =====
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ===== MAP (Ordered) =====
    map<int, string> mp;
    mp[1] = "one";
    mp[3] = "three";
    mp[2] = "two";

    cout << "Map (ordered by key): ";
    for (auto& p : mp) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    // ===== UNORDERED MAP =====
    unordered_map<int, string> ump;
    ump[1] = "one";
    ump[3] = "three";
    ump[2] = "two";

    cout << "Unordered map: ";
    for (auto& p : ump) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    // ===== SET =====
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);

    cout << "Set (ordered unique): ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // ===== UNORDERED SET =====
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(2);

    cout << "Unordered set: ";
    for (int x : us) cout << x << " ";
    cout << "\n";

    return 0;
}
