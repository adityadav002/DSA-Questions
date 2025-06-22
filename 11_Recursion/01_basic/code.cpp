#include <iostream>
using namespace std;

void fun(int n)
{
  if (n == 0)
  {
    cout << "Happy Birthday" << endl;
    return;
  }
  cout << n << " : days left for Birthday" << endl;
  fun(n - 1);
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  fun(n);
  return 0;
}