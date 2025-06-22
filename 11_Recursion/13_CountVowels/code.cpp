#include <iostream>
#include <string>
using namespace std;

int countVowels(string str, int index)
{
  if (index < 0)
    return 0;
  if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
    return 1 + countVowels(str, index - 1);
  else
    return countVowels(str, index - 1);
}
int main()
{
  string str;
  cout << "Enter String: ";
  cin >> str;
  int index = str.length() - 1;
  cout << countVowels(str, index) << endl;
  return 0;
}