#include<iostream>
using namespace std;

int main()
{
  int n=7;
  int arr[n] = {1,0,0,1,0,1,1};

  int start =0, end = n-1;
 while(start<end){

  if(arr[start] == 0 && arr[end] == 1){
    start++;
    end--;
  }else if(arr[start] == 1 && arr[end] == 0){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }else if(arr[start] == 0 && arr[end] == 0){
    start++;
  }
  else{
    end--;
  }

 }
 for(int i=0; i<n-1; i++){
  cout << arr[i] << " ";
 }
  return 0;
}