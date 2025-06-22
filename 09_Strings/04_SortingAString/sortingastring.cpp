#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string sort(string s)
{
  vector<int> alpha(26, 0);
  for (int i = 0; i < s.length(); i++)
  {
    alpha[s[i] - 'a']++;
  }
  string ans;
  for (int i = 0; i < 26; i++)
  {
    char c = 'a' + i;
    while (alpha[i])
    {
      ans += c;
      alpha[i]--;
    }
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << sort(s);
  return 0;
}

// int main()
// {
//   string s;
//   cin>>s;
//   sort(s.begin(),s.end());
//   cout<<s<<endl;
//   return 0;
// }