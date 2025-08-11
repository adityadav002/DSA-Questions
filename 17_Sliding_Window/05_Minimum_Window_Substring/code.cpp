#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int total = t.size();
        vector<int> m(256, 0);
        for (int i = 0; i < t.size(); i++)
            m[t[i]]++;

        int start = 0, end = 0, ans = INT_MAX, index = -1, n = s.size();
        while (end < n) {
            m[s[end]]--;
            if (m[s[end]] >= 0)
                total--;

            while (!total && start <= end) {
                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0)
                    total++;
                start++;
            }
            end++;
        }

        if (index == -1)
            return "";

        return s.substr(index, ans); // more concise than the loop
    }
};

int main() {
    Solution sol;

    string s, t;
    cout << "Enter the source string (s): ";
    cin >> s;

    cout << "Enter the target string (t): ";
    cin >> t;

    string result = sol.minWindow(s, t);

    if (result.empty()) {
        cout << "No valid window found." << endl;
    } else {
        cout << "Minimum window substring: " << result << endl;
    }

    return 0;
}
