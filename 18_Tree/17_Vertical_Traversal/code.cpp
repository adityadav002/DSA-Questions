#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

    void find(Node *root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<int> verticalOrder(Node *root) {
        if (!root) return {};
        int l = 0, r = 0;
        find(root, 0, l, r);
        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(0);

        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
                positive[pos].push_back(temp->data);
            else
                negative[abs(pos)].push_back(temp->data);

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }

            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        vector<int> ans;
        for (int i = negative.size() - 1; i > 0; i--) {
            for (int j = 0; j < negative[i].size(); j++)
                ans.push_back(negative[i][j]);
        }

        for (int i = 0; i < positive.size(); i++) {
            for (int j = 0; j < positive[i].size(); j++)
                ans.push_back(positive[i][j]);
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
    vector<int> result = sol.verticalOrder(root);

    cout << "Vertical Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
