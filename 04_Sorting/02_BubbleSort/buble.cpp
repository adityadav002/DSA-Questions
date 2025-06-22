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
  //Bubble Sort.
  for(int i = n-2; i>=0; i--){
    for(int j=0; j<=i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j],arr[j+1]);
      }
    }
  }

  for(int i=0; i<n; i++){
  cout << arr[i] << " ";
  }
  return 0;
}




/*
Bubble Sort: The algorithm compares each pair of adjacent elements and swaps them if they are in the wrong order. In each iteration, the
adjacent elements are compared, and if they are in the wrong order, they are swapped. This process is repeated until the entire array is sorted.
*/ 

// Time Complexity: O(n²)

/*
Another Method.
for (int i = 0; i < n-1; i++) {
  for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
          swap(arr[j], arr[j+1]);
      }
  }
}
*/