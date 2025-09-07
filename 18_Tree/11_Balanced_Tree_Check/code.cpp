#include <iostream>
#include <cmath>
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
    int height(Node* root, bool &valid) {
        if (!root) return 0;

        int l = height(root->left, valid);
        int r = height(root->right, valid);

        if (abs(l - r) > 1) valid = false;

        return 1 + max(l, r);
    }

    bool isBalanced(Node* root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
};

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    Solution sol;
    if (sol.isBalanced(root1)) {
        cout << "Tree 1 is balanced." << endl;
    } else {
        cout << "Tree 1 is not balanced." << endl;
    }

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    if (sol.isBalanced(root2)) {
        cout << "Tree 2 is balanced." << endl;
    } else {
        cout << "Tree 2 is not balanced." << endl;
    }

    return 0;
}

    
    /*
        Balanced Tree Example:
              1
            /   \
           2     3
          / 
         4
    */

    /*
        Unbalanced Tree Example:
              1
            /
           2
          /
         3
    */