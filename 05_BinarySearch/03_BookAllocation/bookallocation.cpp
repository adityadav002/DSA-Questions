#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bookAllocation(vector<int> arr, int n, int m) {
  if(m>n)
    return -1;

    int start = 0, end = 0, mid, ans = 0;

    for(int i=0; i<n; i++){
      start = max(start, arr[i]);
      end += arr[i];
    }

    while(start <= end){
      mid = start + (end-start)/2;
      int pages = 0, count = 1;
      for( int i =0; i<n; i++){
        pages += arr[i];
        if(pages > mid){
          count++;
          pages = arr[i];
        }
      }
      if(count <= m){
        ans = mid;
        end = mid-1;
      }
      else{
        start = mid+1;
      }
    }

    return ans;
}
int main()
{
  vector<int> arr = {5,10,30,20,15};  
    int n = arr.size();  
    int m = 3;

    int result = bookAllocation(arr, n, m);
    cout << result << endl;

    return 0;
}

