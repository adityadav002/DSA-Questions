#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct Node {
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
    int pathSum(Node *root, int &sum){
        if(!root) return 0;
        
        if(!root->left && !root->right) return root->data;
        
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        
        // left and right both exist.
        if(root->left && root->right){
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }
        
        // only left exists
        if(root->left){
            return root->data + left;
        }

        // only right exists
        return root->data + right;
    }
  
    int maxPathSum(Node* root) {
        int sum = INT_MIN;
        int val = pathSum(root, sum);
        
        if(root->left && root->right)
            return sum;
        
        // If only one subtree exists, return the path through root
        return max(sum, val);
    }
};

Node* buildSampleTree() {
   
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    return root;
}

int main() {
    Node* root = buildSampleTree();

    Solution sol;
    int maxSum = sol.maxPathSum(root);

    cout << "Maximum path sum between two leaves is: " << maxSum << endl;

    return 0;
}

/*
            10
           /  \
          2    10
         / \     \
        20  1     -25
                   / \
                  3   4
*/