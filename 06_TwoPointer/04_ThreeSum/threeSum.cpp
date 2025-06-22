#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void threesum(vector<int>&arr, int n, int key)
{
  sort(arr.begin(),arr.end());
  for(int i=0; i<n; i++)
  {
    int j = i+1, k = n-1;
    while(j<k)
    {
      if(arr[i]+arr[j]+arr[k] == key)
      {
        cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
        j++, k--;
      }
      else if(arr[i]+arr[j]+arr[k] < key)
      {
        j++;
      }
      else
      {
        k--;
      }
    }
  }
}

int main()
{
  vector<int>arr = {-1,0,1,2,-1,-4};
  int n = arr.size(), key = 3;
  threesum(arr,n,key);
  return 0;
}