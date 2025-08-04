#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;

                if (s[i] == ')' && st.top() != '(')
                    return false;
                else if (s[i] == ']' && st.top() != '[')
                    return false;
                else if (s[i] == '}' && st.top() != '{')
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string of brackets: ";
    cin >> input;

    if (sol.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}
