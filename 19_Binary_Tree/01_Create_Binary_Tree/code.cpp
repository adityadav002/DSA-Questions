#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node (int val){
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val){
    if(!root){
        Node *temp = new Node(val);
        return temp;
    } 

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node *root = NULL;

    for(int i=0; i<10; i++){
        root = insert(root, arr[i]);
    }

    inorder(root);

    return 0;
}

/*
                6


*/