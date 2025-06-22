#include <iostream>
using namespace std;

int sum(int n)
{
  return n == 1 ? 1 : n + sum(n - 1);
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  cout << sum(n);
  return 0;
}