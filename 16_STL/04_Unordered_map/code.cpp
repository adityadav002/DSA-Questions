#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["Alice"] = 25;
    m["Bob"] = 30;
    m["Charlie"] = 26;

    for (auto& p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    cout << endl;

    string key = "Bob";

    // Search
    if (m.find(key) != m.end()) {
        cout << key << " found with age " << m[key] << endl;

        // Delete
        m.erase(key);
        cout << key << " deleted." << endl;
    } else {
        cout << key << " not found." << endl;
    }
    cout<<endl;

    for (auto& p : m) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
