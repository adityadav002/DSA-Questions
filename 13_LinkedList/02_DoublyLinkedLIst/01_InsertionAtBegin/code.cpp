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
  Node *head = NULL;
  // Insert at start

  // LinkedList doesn't exist
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