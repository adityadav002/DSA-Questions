#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void mirror(Node* root) {
        if (!root) return;

        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;

        mirror(root->left);
        mirror(root->right);
    }
};

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Original Inorder: ";
    inorderTraversal(root);
    cout << endl;

    Solution sol;
    sol.mirror(root);

    cout << "Mirrored Inorder: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}


    /*
        Sample Tree:
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */
