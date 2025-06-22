#include <iostream>
using namespace std;

// Single Inheritance
class Animal
{
public:
  void eat()
  {
    cout << "Eating..." << endl;
  }
};

class Dog : public Animal
{
public:
  void bark()
  {
    cout << "Barking..." << endl;
  }
};

// Multiple Inheritance
class A1
{
public:
  void msgA()
  {
    cout << "Class A1" << endl;
  }
};

class B1
{
public:
  void msgB()
  {
    cout << "Class B1" << endl;
  }
};

class C1 : public A1, public B1
{
public:
  void msgC()
  {
    cout << "Class C1 (inherits A1 & B1)" << endl;
  }
};

// Multilevel Inheritance
class Grandparent
{
public:
  void show1()
  {
    cout << "Grandparent class" << endl;
  }
};

class Parent : public Grandparent
{
public:
  void show2()
  {
    cout << "Parent class" << endl;
  }
};

class Child : public Parent
{
public:
  void show3()
  {
    cout << "Child class" << endl;
  }
};

// Hierarchical Inheritance
class Base
{
public:
  void baseMethod()
  {
    cout << "Base class method" << endl;
  }
};

class Derived1 : public Base
{
public:
  void derived1Method()
  {
    cout << "Derived1 class method" << endl;
  }
};

class Derived2 : public Base
{
public:
  void derived2Method()
  {
    cout << "Derived2 class method" << endl;
  }
};

// Hybrid Inheritance with Virtual Base
class A2
{
public:
  void show()
  {
    cout << "A2" << endl;
  }
};

class B2 : virtual public A2
{
};
class C2 : virtual public A2
{
};
class D2 : public B2, public C2
{
};

int main()
{
  // Single Inheritance
  Dog d;
  d.eat();
  d.bark();

  // Multiple Inheritance
  C1 c1;
  c1.msgA();
  c1.msgB();
  c1.msgC();

  // Multilevel Inheritance
  Child ch;
  ch.show1();
  ch.show2();
  ch.show3();

  // Hierarchical Inheritance
  Derived1 d1;
  Derived2 d2;
  d1.baseMethod();
  d2.baseMethod();

  // Hybrid Inheritance
  D2 obj;
  obj.show(); // No ambiguity due to virtual inheritance

  return 0;
}
