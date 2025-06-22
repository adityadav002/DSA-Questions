#include<iostream>
using namespace std;

long long int solve(int arr[], int n)
{
  long long max = INT_FAST16_MIN, prefix = 0;
  for(int i = 0; i < n; i++)
  {
    prefix += arr[i];
    max = max > prefix ? max : prefix;
    prefix = prefix < 0 ? 0 : prefix;
  }

  return max;
}

int main()
{
  int arr[5] = {1,2,3,-2,5}, n = 5;
  int result = solve(arr, n);
  cout << result << endl;
  return 0;
}