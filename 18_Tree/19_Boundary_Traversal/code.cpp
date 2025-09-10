#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    void leftSub(Node *root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) return;

        ans.push_back(root->data);
        if (root->left)
            leftSub(root->left, ans);
        else
            leftSub(root->right, ans);
    }

    void leaf(Node *root, vector<int> &ans) {
        if (!root) return;

        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }

        leaf(root->left, ans);
        leaf(root->right, ans);
    }

    void rightSub(Node *root, vector<int> &ans) {
        if (!root || (!root->left && !root->right)) return;

        if (root->right)
            rightSub(root->right, ans);
        else
            rightSub(root->left, ans);

        ans.push_back(root->data); 
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        ans.push_back(root->data); 
        leftSub(root->left, ans);
        if (root->left || root->right)
            leaf(root, ans);
        rightSub(root->right, ans);

        return ans;
    }
};


int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}



// Sample binary tree:
//         20
//        /  \
//      8     22
//     / \      \
//    4  12      25
//      /  \
//     10  14
