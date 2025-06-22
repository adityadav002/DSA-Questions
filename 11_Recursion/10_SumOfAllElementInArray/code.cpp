#include <iostream>
using namespace std;

int sumOfArray(int arr[], int index, int n)
{
  if (index == n)
    return 0;
  return arr[index] + sumOfArray(arr, index + 1, n);
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
  cout << sumOfArray(arr, 0, n);
  return 0;
}