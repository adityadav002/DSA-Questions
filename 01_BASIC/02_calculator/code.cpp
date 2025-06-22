#include<iostream>
using namespace std;
int main()
{
  int a, b, n;
  cout << "Enter First Number : ";
  cin >> a;
  cout << "Enter Second Number : ";
  cin >> b; 

  cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n";
  cin >> n;

  if( n == 1){
    cout << "Addition : " << a + b << endl;
  }else if( n == 2){
    cout << "Subtraction : " << a - b << endl;
  }else if( n == 3){
    cout << "Multiplication : " << a * b << endl;
  }else if( n == 4){
    cout << "Division : " << float(a) / float(b) << endl;
  }

  return 0;
}