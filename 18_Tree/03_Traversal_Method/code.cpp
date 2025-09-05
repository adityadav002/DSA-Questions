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

void PreOrder(Node *root)
{
    if(root == NULL) return;
    cout << root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if(root == NULL) return;
    InOrder(root->left);
    cout << root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data<<" ";
}

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
    cout<<"Enter the Root node: ";
    Node *root;

    // Tree Create.
    root = Binary();

    // Travel: 
    cout<<"\nPreOrder: ";
    PreOrder(root);
    
    cout<<"\nInOrder: ";
    InOrder(root);
   
    cout<<"\nPostOrder: ";
    PostOrder(root);

    return 0;
}

// Example Output:
                // Enter the Root ndde: 1
                // Enter the left node of 1 : 2
                // Enter the left node of 2 : 3
                // Enter the left node of 3 : 4
                // Enter the left node of 4 : -1
                // Enter the right node of 4 : -1
                // Enter the right node of 3 : 5
                // Enter the left node of 5 : -1
                // Enter the right node of 5 : -1
                // Enter the right node of 2 : 6
                // Enter the left node of 6 : -1
                // Enter the right node of 6 : -1
                // Enter the right node of 1 : 7
                // Enter the left node of 7 : -1
                // Enter the right node of 7 : 8
                // Enter the left node of 8 : -1
                // Enter the right node of 8 : 9
                // Enter the left node of 9 : -1
                // Enter the right node of 9 : -1