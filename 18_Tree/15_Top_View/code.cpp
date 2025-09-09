#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    void find(Node *root, int pos, int &l, int &r) {
        if (!root) return;
        l = min(pos, l);
        r = max(pos, r);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<int> topView(Node *root) {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<int> ans(r - l + 1);
        vector<bool> filled(r - l + 1, false);

        queue<Node*> q;
        queue<int> index;

        q.push(root);
        index.push(-1 * l); 

        while (!q.empty()) {
            Node *temp = q.front(); q.pop();
            int pos = index.front(); index.pop();

            if (!filled[pos]) {
                filled[pos] = true;
                ans[pos] = temp->data;
            }

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }

            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        return ans;
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


    /*
        Example Tree:
                1
              /   \
             2     3
              \   / \
               4 5   6
                    /
                   7

        Top View: 2 1 3 6
    */