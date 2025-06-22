#include<iostream>
using namespace std;
int main()
{
  int n;
  cout << "Enter Array Size : ";
  cin >> n;
  int arr[n];
  cout << "Enter Array Elements : " << endl;
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  // Insertion Sort.
  for(int i=1; i<n; i++){
    for(int j=i; j>0; j--){
      if(arr[j] < arr[j-1]){
        swap(arr[j],arr[j-1]);
      }
      else{
        break;
      }
    } 
   }

  for(int i=0; i<n; i++){
  cout << arr[i] << " ";
  }
  return 0;
  
}

// Insertion Sort: The algorithm divides the array into two parts: the sorted part and the unsorted part. The elements are taken from the unsorted part and inserted into their correct position in the sorted part.

// Time Complexity: O(n²)