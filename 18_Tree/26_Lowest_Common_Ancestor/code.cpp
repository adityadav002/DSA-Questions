#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        return left != nullptr ? left : right;
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) return left;
    return findNode(root->right, val);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != nullptr)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;
    return 0;
}

    /*
        Construct the following binary tree:

                 3
                / \
               5   1
              / \ / \
             6  2 0  8
               / \
              7   4

        LCA of 5 and 1 is 3
        LCA of 5 and 4 is 5
    */