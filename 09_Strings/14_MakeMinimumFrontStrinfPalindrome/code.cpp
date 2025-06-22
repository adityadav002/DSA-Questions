#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minChar(string str)
    {
      string rev = str;
      reverse(rev.begin(), rev.end());
      int size = str.size();
      str += '$';
      str += rev;
      
      int n= str.size();
      vector<int>lps(n, 0);
      int pre = 0, suf = 1;
      while(suf < n)
      {
        if(str[pre] == str[suf])
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
      return size - lps[n-1];

    }
};

int main() {
    Solution sol;
    string str;
    cout << "Enter String: ";
    getline(cin, str);
    cout << "Minimum characters to make string palindrome: " << sol.minChar(str) << endl;
    return 0;
}
