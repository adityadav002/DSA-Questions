#include <iostream>
using namespace std;

void lowerToUpper(string &str, int end)
{
  if (end < 0)
  {
    return;
  }
  str[end] = str[end] - 'a' + 'A';
  return lowerToUpper(str, end - 1);
}
int main()
{
  string str;
  cout << "Enter String: ";
  cin >> str;
  int end = str.length() - 1;
  lowerToUpper(str, end);
  cout << str << endl;
  return 0;
}