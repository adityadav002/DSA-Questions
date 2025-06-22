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

  // Insertion at any position
  int pos = 4;
  // insert at start
  if (pos == 0)
  {
    // linked list not exist
    if (head == NULL)
    {
      head = new Node(5);
    }
    // linked list exist
    else
    {
      Node *temp = new Node(5);
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
  }
  else
  {
    Node *curr = head;
    while (pos-- > 0)
    {
      curr = curr->next;
    }
    // insert at end
    if (curr->next == NULL)
    {
      Node *temp = new Node(5);
      temp->prev = curr;
      curr->next = temp;
    }
    // insert at middle
    else
    {
      Node *temp = new Node(5);
      temp->next = curr->next;
      temp->prev = curr;
      curr->next = temp;
      temp->next->prev = temp;
    }
  }

  // Display
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}