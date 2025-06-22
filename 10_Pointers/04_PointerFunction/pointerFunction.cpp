#include<iostream>
#include<vector>
using namespace std;

void swapping(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
  
  cout << "Inside Function : "<< &a << " " << &b << endl; 
  cout << "a = " << a << " , " << "b = " << b << endl;
}


void pass(vector<int>&v)
{
  for(int i = 0; i <= v.size(); i++)
  v[i] = i;
}

void dobfun(int *dou)
{
  for(int i = 0; i < 5; i++)
  dou[i] = dou[i] * 2;
}
int main()
{
  // Swapping Funciton.
  int a=10, b=20;
  swapping(a, b);
  cout << endl;
  cout  << "Outside Function : "<< &a << " " << &b << endl; 
  cout << "a = " << a << " , " << "b = " << b << endl;

  // Vector Function.
  vector<int>v(5,0);
  pass(v);
  cout << endl;
  for(int i = 1; i <= v.size(); i++)
  cout << v[i] << " ";
  cout << endl << endl;

  // Double array value with pointer.
  int dou[5] = {1,2,3,4,5};
  dobfun(dou);
  for(int i = 0; i < 5; i++)
  cout << dou[i] << " ";

  return 0;
}