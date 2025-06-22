#include<iostream>
using namespace std;

int main() 
{
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;

   cout << arr << endl;
   cout << arr + 0 << endl;
   cout << &arr[0] << endl;
   cout << ptr << endl;

   for(int i=0; i<5; i++){
     cout << *(ptr + i) << " ";
   }
   cout<<endl;

   for(int i=0; i<5; i++){
    cout << *ptr << " ";
    ptr++;
   }
   cout<<endl;
   
   int *ptr1 = &arr[4];
   for(int i=4; i>=0; i--){
    cout << *ptr1 << " ";
    ptr1--;
   }
   return 0;
}