#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
  vector<int> temp(end - start + 1);
  int left = start, right = mid + 1, index = 0;

  // merging process.
  while (left <= mid && right <= end)
  {
    if (arr[left] <= arr[right])
    {
      temp[index++] = arr[left++];
    }

    else
    {
      temp[index++] = arr[right++];
    }
  }

  // remaining elements of left.
  while (left <= mid)
  {
    temp[index++] = arr[left++];
  }

  // remaining elements of right.
  while (right <= end)
  {
    temp[index++] = arr[right++];
  }

  // copying back to original array.
  for (int i = start; i <= end; i++)
  {
    arr[i] = temp[i - start];
  }
}

void mergeSort(int arr[], int start, int end)
{

  if (start == end)
    return;

  int mid = start + (end - start) / 2;
  // split left side.
  mergeSort(arr, start, mid);
  // split right side.
  mergeSort(arr, mid + 1, end);
  // merge.
  merge(arr, start, mid, end);
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
  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}