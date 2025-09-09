#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            ans.push_back(q.front()->data); 

            while (n--) {
                Node *temp = q.front();
                q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.leftView(root);

    cout << "Left View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


    /*
        Sample Tree:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

/*
Solve using Recursion.
class Solution {
  public:
  
  void Lview(Node *root, vector<int>&ans, int level){
      if(!root) return;
      
      if(level == ans.size())
      ans.push_back(root->data);
      
      Lview(root->left, ans, level+1);
      Lview(root->right, ans, level+1);
  }
    vector<int> leftView(Node *root) {
     vector<int> ans;
     if(!root) return ans;
     Lview(root, ans, 0);
     return ans;
    }
};
*/