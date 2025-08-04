#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> bracketNumber(string s) {
        int count = 0;
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                st.push(count);
                ans.push_back(count);
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string with parentheses: ";
    cin >> input;

    vector<int> result = sol.bracketNumber(input);

    cout << "Bracket numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
