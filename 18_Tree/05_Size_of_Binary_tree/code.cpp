#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void Total(Node* root, int &count) {
        if (root == NULL) return;

        count++;
        Total(root->left, count);
        Total(root->right, count);
    }

    int getSize(Node* root) {
        int count = 0;
        Total(root, count);
        return count;
    }
};

// Main function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int size = sol.getSize(root);
    
    cout << "Size of the binary tree is: " << size << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/*
       1
      / \
     2   3
    / \
    4   5
*/