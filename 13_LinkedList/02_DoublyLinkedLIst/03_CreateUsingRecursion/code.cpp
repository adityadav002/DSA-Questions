#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

Node *createDLL(int arr[], int index, int size, Node *back)
{
  if (index == size)
  {
    return NULL;
  }

  Node *temp = new Node(arr[index]);
  temp->prev = back;
  temp->next = createDLL(arr, index + 1, size, temp);
  return temp;
}
int main()
{
  Node *head = NULL;
  int arr[] = {1, 2, 3, 4, 5};

  // create using recursion
  head = createDLL(arr, 0, 5, NULL);

  // Display
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}