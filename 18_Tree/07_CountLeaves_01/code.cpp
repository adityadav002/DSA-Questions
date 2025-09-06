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
    void countLeaf(Node *root, int &count) {
        if (!root) return;

        if (!root->left && !root->right) {
            count++;
            return;
        }

        countLeaf(root->left, count);
        countLeaf(root->right, count);
    }

    int countLeaves(Node* root) {
        int count = 0;
        countLeaf(root, count);
        return count;
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
    cout << "Number of leaf nodes in the binary tree: " << leafCount << endl;

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

        Leaf nodes: 3, 7, 18 → count = 3
    */