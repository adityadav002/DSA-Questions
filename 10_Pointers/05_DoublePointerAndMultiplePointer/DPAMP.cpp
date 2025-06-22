#include<iostream>
using namespace std;


void function(int **p1)
{
  **p1 = **p1 + 5;
}
int main()
{
  int a = 10;
  int *p = &a;
  int **p1 = &p;

  cout << p1 << endl;
  function(p1);
  cout << **p1 << endl;

  return 0;
}