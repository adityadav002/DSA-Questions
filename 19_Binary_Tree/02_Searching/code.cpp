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

bool search(Node *root, int target){
    if(!root) return 0;

    if(root->data == target){
        return 1;
    }

    if(root->data > target)
        return search(root->left, target);
    else
        return search(root->right, target);

    return 0;
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node *root = NULL;
    int target = 18; 
    for(int i=0; i<10; i++){
        root = insert(root, arr[i]);
    }

    int result = search(root, target);
    cout << result;
    return 0;
}
