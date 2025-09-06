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
    int countLeaves(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    Solution sol;
    int leafCount = sol.countLeaves(root);
    cout << "Number of leaf nodes: " << leafCount << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

/*
    Constructing this binary tree:
       10
      /  \
     5    15
    / \     \
    3   7     18

*/