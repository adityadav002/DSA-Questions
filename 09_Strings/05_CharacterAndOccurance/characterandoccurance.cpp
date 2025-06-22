#include<iostream>
#include<cctype> 
using namespace std;

void solution(string str)
{
  int count[26] = {0};
  for(int i = 0; i < str.length(); i++)
  {
    char ch = tolower(str[i]);
    if(ch >= 'a' && ch <= 'z')
      count[ch - 'a']++;
  }

  for(int i = 0; i < 26; i++)
  {
    if(count[i] != 0){
      cout << char(i + 'a') << " " << count[i] << endl;
    }
  }
}

int main()
{
  string str;
  cout << "Enter a String" << endl;
  getline(cin, str);

  solution(str);

  return 0;
}
