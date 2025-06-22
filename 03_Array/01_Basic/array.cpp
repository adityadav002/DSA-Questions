#include<iostream>
using namespace std;
int main()
{
  int n;
  cout << "Enter Array Size : ";
  cin >> n;

  cout << "Enter Array Elements : " << endl;
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << "Array Elements are : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}