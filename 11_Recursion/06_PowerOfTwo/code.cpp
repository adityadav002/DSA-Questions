#include <iostream>
using namespace std;

int power(int nums, int n)
{
  return n == 1 ? nums : nums * power(nums, n - 1);
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  cout << power(2, n);
  return 0;
}