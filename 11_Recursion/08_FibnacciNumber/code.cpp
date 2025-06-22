#include <iostream>
using namespace std;

int fibnac(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  return fibnac(n - 1) + fibnac(n - 2);
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  cout << fibnac(n);
  return 0;
}