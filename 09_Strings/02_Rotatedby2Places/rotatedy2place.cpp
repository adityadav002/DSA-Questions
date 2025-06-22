#include<iostream>
#include<string>
using namespace std;

void rotateClockWise(string &str)
{
char c = str[str.length() - 1];
int index = str.length()-2;
while (index>0)
{
  str[index+1] = str[index];
  index--;
}
str[0] = c;
}

void rotateAntiClockWise(string &str)
{
  char c = str[0];
  int index = 1;
  while (index<str.length())
  {
    str[index-1] = str[index];
    index++;
  }
  str[str.length()-1] = c;
}

 bool rotateString(string s1, string s2)
 {

  if(s1.length() != s2.length())
  {
    return false;
  }
  string clockwise = s1, anticlockwise = s1;
  rotateClockWise(clockwise);
  rotateClockWise(clockwise);
  if(clockwise == s2){
    return true;
  }

  rotateAntiClockWise(anticlockwise);
  rotateAntiClockWise(anticlockwise);
  if(anticlockwise == s2){
    return true;
  }
  return false;

 }

int main()
{
   string s1 = "amazon", s2 = "azonam";
   cout << rotateString(s1, s2);
   return 0;
}