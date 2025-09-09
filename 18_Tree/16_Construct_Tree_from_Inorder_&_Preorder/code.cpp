#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int findPosition(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) return i;
        }
        return -1;
    }

    Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return NULL;
 
        Node* root = new Node(preorder[preIndex++]);
        if (inStart == inEnd) return root;
        int inIndex = findPosition(inorder, root->data, inStart, inEnd);
        root->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex);
        root->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex);
        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preIndex = 0;
        return buildTreeHelper(inorder, preorder, 0, inorder.size() - 1, preIndex);
    }
};

void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> inorder  = {3, 1, 4, 0, 2, 5};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    Solution sol;
    Node* root = sol.buildTree(inorder, preorder);
    printPostorder(root);
    cout << endl;

    return 0;
}
