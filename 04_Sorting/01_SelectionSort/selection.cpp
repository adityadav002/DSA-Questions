#include<iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Array Size : ";
  cin >> n;
  int arr[n];
  cout << "Enter Array Elements : " << endl;
  for(int i=0; i<n; i++){
  cin >> arr[i];
  }
  
  // Selction Sort.
  for(int i=0; i<n-1; i++){
    int index = i;
    for(int j=i+1;j<n;j++){
      if(arr[j] < arr[index]){
        index = j;
    }
  }
  swap(arr[i],arr[index]);
  }

  for(int i=0; i<n; i++){
  cout << arr[i] << " ";
  }
return 0;
}

// Selection sort: The algorithm selects the minimum (or maximum) element from the unsorted part of the array and swaps it with the element at the beginning of the unsorted part.

// Time Complexity: O(n²)