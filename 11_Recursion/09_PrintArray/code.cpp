#include <iostream>
using namespace std;

void printArray(int arr[], int index)
{
  if (index == -1)
    return;

  printArray(arr, index - 1);
  cout << arr[index] << " ";
}

void printRerverseArray(int arr[], int index)
{
  if (index == -1)
    return;

  cout << arr[index] << " ";
  printRerverseArray(arr, index - 1);
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
  printArray(arr, 4);
  cout << endl;
  printRerverseArray(arr, 4);
  return 0;
}