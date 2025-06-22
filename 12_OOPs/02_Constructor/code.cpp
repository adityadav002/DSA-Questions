#include <iostream>
using namespace std;

class Student
{
public:
  int roll_no;
  string name;
  int marks;

  // Default Constructor
  Student()
  {
    roll_no = 0;
    name = "Unknown";
    marks = 0;
    cout << "Default Constructor called" << endl;
  }

  // Parameterized Constructor
  Student(int r, string n, int m)
  {
    roll_no = r;
    name = n;
    marks = m;
    cout << "Parameterized Constructor called" << endl;
  }

  // Copy Constructor
  Student(const Student &s)
  {
    roll_no = s.roll_no;
    name = s.name;
    marks = s.marks;
    cout << "Copy Constructor called" << endl;
  }

  // Display function
  void display()
  {
    cout << "Roll No: " << roll_no << endl;
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "------------------------" << endl;
  }
};

int main()
{
  // Default constructor
  Student s1;
  s1.display();

  // Parameterized constructor
  Student s2(1, "Aditya", 95);
  s2.display();

  // Copy constructor
  Student s3 = s2;
  s3.display();

  return 0;
}
