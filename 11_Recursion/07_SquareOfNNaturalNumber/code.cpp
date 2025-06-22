#include <iostream>
using namespace std;

int square(int n)
{
  return n == 1 ? 1 : n * n + square(n - 1);
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  cout << square(n);
  return 0;
}