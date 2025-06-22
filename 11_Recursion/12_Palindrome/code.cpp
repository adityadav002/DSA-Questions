#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string str, int start, int end)
{
  if (start >= end)
    return 1;

  if (str[start] != str[end])
    return 0;
  else
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
  string str;
  cout << "Enter a String : ";
  cin >> str;
  int start = 0;
  int end = str.length() - 1;
  cout << isPalindrome(str, start, end) << endl;
  return 0;
}