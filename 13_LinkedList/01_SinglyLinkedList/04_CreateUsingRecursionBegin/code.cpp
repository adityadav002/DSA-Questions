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

NODE *createLinkedList(int arr[], int index, int n, NODE *prev)
{
  if (index == n)
    return prev;

  NODE *temp = new NODE(arr[index]);
  temp->next = prev;
  return createLinkedList(arr, index + 1, n, temp);
}
int main()
{
  NODE *Head = NULL;
  int arr[] = {2, 4, 6, 8, 10};

  Head = createLinkedList(arr, 0, 5, Head);
  // Print the value.
  NODE *temp = Head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}