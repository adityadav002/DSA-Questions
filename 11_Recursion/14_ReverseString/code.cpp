#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end)
{
  if (start >= end)
  {
    return;
  }
  swap(str[start], str[end]);
  return reverseString(str, start + 1, end - 1);
}
int main()
{
  string str;
  cout << "Enter String: ";
  cin >> str;
  int start = 0;
  int end = str.length() - 1;
  reverseString(str, start, end);
  cout << str << endl;
  return 0;
}