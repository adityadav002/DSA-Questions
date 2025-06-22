#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Array Size : ";
  cin >> n;

  cout << "Enter Array Elements : " << endl;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    sum += arr[i];
  }

  int total = (n * (n + 1)) / 2;

  cout << "Missing Number is : " << total - sum << endl;
  return 0;
}