#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void minDist(TreeNode *root, int &prev, int &ans) {
        if (!root) return;

        minDist(root->left, prev, ans);
        if (prev != INT_MIN)
            ans = min(ans, root->val - prev);
        prev = root->val;
        minDist(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        minDist(root, prev, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.minDiffInBST(root);
    cout << "Minimum difference in BST: " << result << endl;

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

    /*
        Construct the following BST:
              4
             / \
            2   6
           / \
          1   3
    */