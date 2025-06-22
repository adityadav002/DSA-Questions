#include <iostream>
using namespace std;

class Student
{
public:
  int roll_no;
  string name;
  int marks;

public:
  void set_data(int a, string b, int c)
  {
    roll_no = a;
    name = b;
    marks = c;
  }

  void get_data()
  {
    cout << roll_no << " " << name << " " << marks << endl;
  }
};
int main()
{
  Student s1;
  s1.set_data(1, "Aditya", 100);
  s1.get_data();
  return 0;
}
