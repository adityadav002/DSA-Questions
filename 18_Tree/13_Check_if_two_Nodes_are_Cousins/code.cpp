#include <iostream>
#include <queue>
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
    bool isCousins(Node* root, int x, int y) {
        if (!root) return false;

        queue<pair<Node*, Node*>> q; // (node, parent)
        q.push(make_pair(root, (Node*)nullptr));  // fix: explicit nullptr type

        while (!q.empty()) {
            int size = q.size();
            Node* parentX = nullptr;
            Node* parentY = nullptr;

            for (int i = 0; i < size; ++i) {
                Node* node = q.front().first;
                Node* parent = q.front().second;
                q.pop();

                if (node->data == x) parentX = parent;
                if (node->data == y) parentY = parent;

                if (node->left) q.push(make_pair(node->left, node));
                if (node->right) q.push(make_pair(node->right, node));
            }

            if (parentX && parentY) {
                return parentX != parentY; // Same level, different parent
            } else if (parentX || parentY) {
                return false; // One found without the other
            }
        }

        return false;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    Solution sol;

    int x = 4, y = 5;

    bool result = sol.isCousins(root, x, y);

    if (result)
        cout << "Yes, " << x << " and " << y << " are cousins." << endl;
    else
        cout << "No, " << x << " and " << y << " are not cousins." << endl;

    return 0;
}
