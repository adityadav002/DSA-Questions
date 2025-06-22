#include <iostream>
using namespace std;

class NODE
{
public:
  int data;
  NODE *next;
  NODE(int value)
  {
    data = value;
    next = NULL;
  }
};
int main()
{
  NODE *Head;
  Head = new NODE(4);
  cout << Head->data << endl;
  cout << Head->next << endl;
  return 0;
}