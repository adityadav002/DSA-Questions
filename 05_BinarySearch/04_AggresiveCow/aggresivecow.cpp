#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve (vector<int> &stall,int n, int k )
{
  int start = 1, end, mid, ans;
  sort(stall.begin(),stall.end());

  end = stall[n-1] - stall[0];

  while(start <= end)
  {
    mid = start + (end-start)/2;
    int count  = 1, pos = stall[0];
    for(int i=1; i<n; i++){
      if(pos + mid <= stall[i]){
        count++;
        pos = stall[i];
    }
    }
      if(count < k){
        end = mid-1;
      }
      else{
        ans = mid;
        start = mid+1;
      }
  }
  return ans;

}
int main()
{
  vector<int>stall = {1,2,4,8,9};
  int n = stall.size();
  int k = 3;
  
  int result = solve(stall, n, k);
  cout << result << endl;
  return 0;
}