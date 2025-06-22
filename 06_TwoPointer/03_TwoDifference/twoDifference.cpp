#include<iostream>
using namespace std;

int twoDifference(int arr[], int target, int &startValue, int &endValue)
{
 int start = 0, end = 1;
 while(end < 6)
   {
    if(arr[end] - arr[start] == target){
      startValue = arr[start];
      endValue = arr[end];
      return true;
    }
    else if(arr[end] - arr[start] < target){
     end++;
    }
    else {
      start++;
    }
   }
   return false;
}

int main()
{
   int arr[6] = {1,2,4,6,18,25}, target = 4, startValue, endValue;
   int result  = twoDifference(arr, target, startValue, endValue);
   
   if (twoDifference(arr, target, startValue, endValue)) {
    cout << "Start: " << startValue << ", End: " << endValue << endl;
   } else {
    cout << "No such pair found." << endl;
   }

   return 0;
}