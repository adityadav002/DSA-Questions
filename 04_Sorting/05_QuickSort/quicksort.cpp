#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{
  int pivot = arr[end];
  int pos = start;
  for (int i = start; i < end; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[pos], arr[i]);
      pos++;
    }
  }
  swap(arr[pos], arr[end]);
  return pos;
}

void quickSort(int arr[], int start, int end)
{
  if (start >= end)
    return;
  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end); // Move to the right of pivot
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
