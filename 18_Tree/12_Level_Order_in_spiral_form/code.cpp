#include <iostream>
#include <stack>
#include <vector>
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
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        
        stack<Node*> s1; 
        stack<Node*> s2;  

        s1.push(root);
        vector<int> ans;

        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);

                if (temp->right) s2.push(temp->right);
                if (temp->left) s2.push(temp->left);
            }
            while (!s2.empty()) {
                Node* temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);

                if (temp->left) s1.push(temp->left);
                if (temp->right) s1.push(temp->right);
            }
        }

        return ans;
    }
};


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    Solution sol;
    vector<int> res = sol.findSpiral(root);

    cout << "Spiral Order Traversal: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


    /*
        Tree:
              1
            /   \
           2     3
          / \   / \
         7   6 5   4
    */