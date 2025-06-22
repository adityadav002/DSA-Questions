#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// My Solution.
void solve(int arr[], int n)
{
  int newArr[n];
  for(int i = 0; i < n; i++){
    newArr[i] = 1;
  }

 for(int i=0; i<=n-1; i++)
 {
  swap(arr[i], arr[n-1]);
  for(int j=0; j<=n-2; j++)
  {
    newArr[i] = newArr[i] * arr[j];
  }
  swap(arr[i], arr[n-1]);
 }
 
 for(int i=0; i<n; i++)
 {
  cout<< newArr[i]<<" ";
 }
}

// Optimal Solution.
void solve2(int nums[], int n)
{
            vector<int> res(n,1);
            int left = 1;
            int right = 1;
            for(int i=0; i<n; i++) {
                res[i] *= left;
                left *= nums[i];
                res[n-1-i] *= right;
                right *= nums[n-1-i];
            }
           for(int i=0; i<n; i++)
           {
            cout<< res[i]<<" ";
           }
     
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
  cin >> arr[i];
  solve(arr,n);
  solve2(arr,n);
  return 0;
}