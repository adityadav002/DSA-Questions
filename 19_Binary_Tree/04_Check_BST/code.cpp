#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void inorder(Node *root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    bool isBST(Node* root) {
        vector<int> ans;
        inorder(root, ans);
        
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution sol;
    if (sol.isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is NOT a BST." << endl;
    }

    return 0;
}