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

NODE *deleteNodeAtPosition(NODE *head, int pos)
{
  if (head == NULL)
    return NULL;

  if (pos == 1)
  {
    NODE *temp = head->next;
    delete head;
    return temp;
  }

  head->next = deleteNodeAtPosition(head->next, pos - 1);
  return head;
}

void displayList(NODE *head)
{
  if (head == NULL)
    return;
  cout << head->data << " ";
  displayList(head->next);
}

int main()
{
  NODE *Head = NULL;
  int arr[] = {2, 4, 6, 8, 10};
  int pos = 3;

  Head = createLinkedList(arr, 0, 5);

  cout << "Original List: ";
  displayList(Head);
  cout << endl;

  Head = deleteNodeAtPosition(Head, pos);

  cout << "After Deletion at position " << pos << ": ";
  displayList(Head);
  cout << endl;

  return 0;
}
