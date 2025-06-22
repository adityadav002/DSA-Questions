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

int main()
{
  Node *head = NULL, *tail = NULL;
  int arr[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
  {
    // Linked List doesn't exist
    if (head == NULL)
    {
      head = new Node(arr[i]);
      tail = head;
    }
    // Linked List exists
    else
    {
      Node *temp = new Node(arr[i]);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }

  // Insertion at start.
  if (head == NULL)
    head = new Node(5);

  // ALready exist
  else
  {
    Node *temp = new Node(5);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  // Display the linked list
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}