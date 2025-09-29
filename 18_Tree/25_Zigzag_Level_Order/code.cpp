#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }

        return result;
    }
};

void printZigzagOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    printZigzagOrder(result);

    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

    /*
        Sample Binary Tree:
               1
              / \
             2   3
            / \   \
           4   5   6

        Expected Zigzag Level Order:
        [
            [1],
            [3, 2],
            [4, 5, 6]
        ]
    */

    // Creating the tree nodes