#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int>& path, int currentSum) {
        if (node == nullptr) return;

        path.push_back(node->val);
        currentSum += node->val;

        if (node->left == nullptr && node->right == nullptr && currentSum == targetSum) {
            result.push_back(path);
        }

        dfs(node->left, targetSum, path, currentSum);
        dfs(node->right, targetSum, path, currentSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


    /*
            5
           / \
          4   8
         /   / \
       11   13  4
      /  \     / \
     7    2   5   1
    */

    