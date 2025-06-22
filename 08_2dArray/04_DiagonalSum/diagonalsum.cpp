#include<iostream>
using namespace std;
int main()
{
  int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}} ;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl; 

  int sum = 0;
  for (int i = 0; i < 3; i++) {
      sum += arr[i][i];
  }
  
  int sum1 = 0;
    for (int i = 0; i < 3; i++) {
        sum1 += arr[i][2 - i]; 
  }

  cout << "Diagonal Sum is : " << sum << endl;
  cout << "Reverse Diagonal Sum is : " << sum1 << endl;
  return 0;
}
