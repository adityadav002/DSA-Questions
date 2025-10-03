#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root){
    if(!root) return 0;

    return root->height;
}

int getBalance(Node *root){
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root){
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *leftRotation(Node *root){
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{
    // Insert Element.
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
    return root;

    // Update Height.
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balancing Check.
    int balance = getBalance(root);

    // LL
    if(balance>1 && key<root->left->data){
        return rightRotation(root);
    }
    // RR
    else if(balance<-1 && key>root->right->data){
        return leftRotation(root);
    }
    // LR
    else if(balance>1 && key>root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // RL
    else if(balance<-1 && key<root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalancing
    else{
        return root;
    }
}

void preorder(Node *root){
    if(!root) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);
}