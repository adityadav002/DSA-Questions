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
  Head = NULL;

  int arr[] = {2, 4, 6, 8, 10};
  // Insert the node in beginning.
  for (int i = 0; i < 5; i++)
  {
    // Linked List doesn't exist.
    if (Head == NULL)
    {
      Head = new NODE(arr[i]);
    }
    // Linked List exists.
    else
    {
      NODE *temp;
      temp = new NODE(arr[i]);
      temp->next = Head;
      Head = temp;
    }
  }

  // Print the value.
  NODE *temp = Head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}