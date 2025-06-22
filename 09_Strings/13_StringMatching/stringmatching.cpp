#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void lpsfind(vector<int>& lps, string s)
    {
        int pre = 0, suf = 1;
        while(suf < s.size())
        {
            if(s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else {
                if(pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else {
                    pre = lps[pre-1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;
        while(first < haystack.size())
        {
            if(haystack[first] == needle[second])
            {
                first++, second++;
                if(second == needle.size())
                    return first - second;
            }
            else {
                if(second == 0){
                    first++;
                }
                else{
                    second = lps[second - 1];
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string haystack, needle;

    cout << "Enter haystack string: ";
    getline(cin, haystack);

    cout << "Enter needle string: ";
    getline(cin, needle);

    int index = sol.strStr(haystack, needle);

    if(index != -1)
        cout << "Needle found at index: " << index << endl;
    else
        cout << "Needle not found in haystack." << endl;

    return 0;
}
