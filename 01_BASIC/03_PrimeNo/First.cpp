#include<iostream>
using namespace std;
int main()
{
 int a;
 int b = 1;
 cout << "Enter Your Number : ";
 cin >> a;

 for(int i = 2; i<=a; i++){
  if(a % i == 0){
    b++;
 }
 }
 if(b==2){
  cout << "Prime Number" << endl;
 }
 else{
  cout << "Not Prime Number" << endl;
 }
 return 0;
}