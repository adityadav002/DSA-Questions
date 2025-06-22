#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to compute the LPS (Longest Prefix which is also Suffix) array
    vector<int> computeLPS(string s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }

        return lps;
    }
};

int main() {
    Solution sol;
    string str;

    cout << "Enter the string to compute LPS: ";
    getline(cin, str);

    vector<int> lps = sol.computeLPS(str);

    cout << "LPS array: ";
    for (int val : lps) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
