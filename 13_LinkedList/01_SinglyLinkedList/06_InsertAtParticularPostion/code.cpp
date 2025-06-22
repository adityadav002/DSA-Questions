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
  if (n == index)
  {
    return NULL;
  }
  NODE *temp = new NODE(arr[index]);
  temp->next = createLinkedList(arr, index + 1, n);
  return temp;
}
int main()
{
  NODE *Head = NULL;
  int arr[] = {2, 4, 6, 8, 10};

  Head = createLinkedList(arr, 0, 5);

  // Inert at particular position
  int x = 3;
  int value = 30;
  NODE *temp = Head;
  x--;
  while (x--)
  {
    temp = temp->next;
  }
  NODE *newNode = new NODE(value);
  newNode->next = temp->next;
  temp->next = newNode;

  // Print the value.
  temp = Head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}