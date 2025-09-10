#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        while (root) {
            // If left child doesn't exist
            if (!root->left) {
                ans.push_back(root->data);
                root = root->right;
            } 
            // If left child exists
            else {
                Node* curr = root->left;
                // Find the rightmost node in the left subtree or thread back to root
                while (curr->right && curr->right != root)
                    curr = curr->right;

                // If threading does not exist, create one
                if (curr->right == nullptr) {
                    curr->right = root;
                    root = root->left;
                } 
                // Thread already exists, revert it and move to right subtree
                else {
                    curr->right = nullptr; 
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.inOrder(root);

    cout << "Inorder Traversal (Morris): ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}


    // Create binary tree manually
    /*
              1
             / \
            2   3
           / \
          4   5
    */