#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *Binary()
{
    int x;
    cin >> x;
    if(x == -1){
        return NULL;
    }

    Node *temp = new Node(x);
    // Left node.
    cout<<"Enter the left node of "<<x<<" : ";
    temp->left = Binary();

    // Right node.
    cout<<"Enter the right node of "<<x<<" : ";
    temp->right = Binary();

    return temp;
}

int main()
{
    cout<<"Enter the Root Element of the Tree: ";
    Node *root;
    root = Binary();
}

