#include <iostream>
using namespace std;
int waysToSum(int arr[], int n, int sum)
{
  if (sum == 0)
    return 1;
  if (sum < 0)
    return 0;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += waysToSum(arr, n, sum - arr[i]);
  }
  return ans;
}

int main()
{
  int arr[] = {5, 6, 1}, n = 3, sum = 7;
  cout << waysToSum(arr, n, sum) << endl;
  return 0;
}