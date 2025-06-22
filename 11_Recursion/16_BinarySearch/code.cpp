#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int n, int key, int start, int end, int mid)
{
  if (start > end)
    return 0;
  mid = start + (end - start) / 2;

  if (arr[mid] == key)
    return 1;
  else if (arr[mid] < key)
    return BinarySearch(arr, n, key, mid + 1, end, mid);
  else
    return BinarySearch(arr, n, key, start, mid - 1, mid);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5}, n = sizeof(arr) / sizeof(arr[0]), key = 3, start = 0, end = n - 1, mid;
  cout << BinarySearch(arr, n, key, start, end, mid);
}