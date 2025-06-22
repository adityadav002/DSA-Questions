#include<iostream>
using namespace std;

int main()
{
  int arr[6] = {1,2,4,6,18,25};
  int target = 10, start = 0, end = 5;
  while(start < end)
  {
    if(arr[start] + arr[end] == target){
      cout << arr[start] << " " << arr[end] << endl;
      break;
    }
    else if(arr[start] + arr[end] > target){
      end--;
    }
    else{
      start++;
    }
  }
  return 0;
}