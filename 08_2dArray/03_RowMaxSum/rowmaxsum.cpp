#include<iostream>
using namespace std;
int main()
{
  int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  int ans = INT_FAST16_MIN, index = 0;
  for(int i=0; i<3; i++){
    int max = 0;
    for(int j=0; j<3; j++){
      max += arr[i][j];
      if(max > ans){
        ans = max;
        index = i;
      }
    }
  }

  cout << "Maximum Sum is : " << ans << " and Index is : " << index <<endl;
  return 0;
}