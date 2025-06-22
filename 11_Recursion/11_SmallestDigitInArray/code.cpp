#include <iostream>
using namespace std;

int minElement(int arr[], int index, int n)
{
  if (index == n - 1)
    return arr[index];
  return min(arr[index], minElement(arr, index + 1, n));
}
int main()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  cout << "Enter Array Elements : ";
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << minElement(arr, 0, n);
  return 0;
}