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

NODE *createLinkedList(int arr[], int index, int n)
{
  if (index == n)
    return NULL;

  NODE *temp = new NODE(arr[index]);
  temp->next = createLinkedList(arr, index + 1, n);
  return temp;
}

int main()
{
  NODE *Head = NULL;
  int arr[] = {2, 4, 6, 8, 10};

  Head = createLinkedList(arr, 0, 1);

  // delete Last node.
  if (Head != NULL)
  {
    NODE *temp = Head;
    NODE *prev = NULL;
    while (temp->next != NULL)
    {
      prev = temp;
      temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
  }

  // Display
  NODE *temp = Head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}