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
    void KLargest(Node *root, int &ans, int &k) {
        if (!root || k <= 0) return;

        KLargest(root->right, ans, k);

        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        KLargest(root->left, ans, k);
    }

    int kthLargest(Node *root, int k) {
        int ans = -1;
        KLargest(root, ans, k);
        return ans;
    }
};

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    Solution sol;
    int k = 3;
    int result = sol.kthLargest(root, k);
    cout << "The " << k << "rd largest element is: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

  /*
        Construct the following BST:
              50
             /  \
           30    70
          / \    / \
        20  40  60  80

        In-order:       20 30 40 50 60 70 80
        Reverse In-order: 80 70 60 50 40 30 20
  */