#include<iostream>
#include<string>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  cout<<str<<endl;

  cout << "Length/Size of string is : " << str.length() << endl;

  string str2 = "Hello", str3 = "World!";
  cout << str2 + str3 << endl;

  string str4 = "Hello";
  str4.push_back('!');
  cout << str4 << endl;

  string reverse = "Hello";
  int start = 0, end = reverse.length() - 1;
  while (start < end){
    swap(reverse[start], reverse[end]);
    start++, end--;
  }
  cout << reverse << endl;

  string str5 = "naman";
  start = 0, end = str5.length() - 1;
  while (start < end){
    if (str5[start] != str5[end]){
      cout << "Not a Palindrome" << endl;
      return 0;
    }
    start++, end--;
  }
  cout << "Palindrome" << endl;

  return 0;
}