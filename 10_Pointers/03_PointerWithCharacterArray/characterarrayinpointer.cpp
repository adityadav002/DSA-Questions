#include<iostream>
using namespace std;

int main()
{
  char arr[5] = "1234";
  char *ptr = arr;

  // if i try to print address of an char array it will print its value.
  cout<< arr << endl;
  cout << ptr << endl;

  // by this way we can print address of an char array
  cout << (void *)arr << endl;
  cout << (void *)ptr << endl;

  char name = 'a';
  char *ptr1 = &name;
  cout << name << endl;
  cout << "This one : " << ptr1 << endl;
  cout << (void*)&name<< endl;
  cout << (void*)ptr1 << endl;
  return 0;
}