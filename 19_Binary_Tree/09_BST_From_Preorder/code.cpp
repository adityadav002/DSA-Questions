#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* BST(vector<int> &preorder, int &index, int lower, int upper) {
        if (index == preorder.size() || preorder[index] < lower || preorder[index] > upper)
            return NULL;

        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = BST(preorder, index, lower, root->val);
        root->right = BST(preorder, index, root->val, upper);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
