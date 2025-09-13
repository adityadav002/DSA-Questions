#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node *deleteNode(Node *root, int x) {
        if(!root) return NULL;
        
        if(root->data > x){
            root->left = deleteNode(root->left, x);
            return root;
        }
        else if(root->data < x){
            root->right = deleteNode(root->right, x);
            return root;
        }
        else{
            // leaf node.
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // 1 child exists.
            else if(!root->right){    // left child exists
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left){     // right child exists
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // 2 children exist.
            else{
                // find the greatest element from left
                Node *child = root->left;
                Node *parent = root;
                while(child->right){
                    parent = child;
                    child = child->right;
                }
                if(root != parent){
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else{
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    Solution sol;

    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : elements) {
        root = insert(root, val);
    }

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int x = 50;
    root = sol.deleteNode(root, x);

    cout << "Inorder after deleting " << x << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
