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

    for(int i=n-1; i>=0; i--){
      cout << arr[i] << " ";
    }
    return 0;
}