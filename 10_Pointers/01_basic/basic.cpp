#include<iostream>
using namespace std;

int main()
{
  float a = 10.5;
  cout << "Value of a is : " << a << endl;
  float *ptr = &a;
  float **dptr = &ptr;
  cout << "Dereference of a(*ptr) is : " << *ptr << endl;
  cout << "Dereference of a(*dptr) is : " << **dptr << endl;
  cout << "Address of a(&a) is : " << &a << endl;
  cout << "Address of a(ptr) is : " << ptr << endl;
  cout << "Address of a(dptr) is : " << dptr << endl;
  cout<< "Address of a(&ptr) is : " << &ptr << endl;
  cout << "Size of a is : " << sizeof(a) << endl;
  cout << "Size of ptr is : " << sizeof(ptr) << endl;
  cout << "Size of dptr is : " << sizeof(dptr) << endl;
  return 0;
}