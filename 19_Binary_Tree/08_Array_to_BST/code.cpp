#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* ArrayToBST(vector<int> &arr, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);

        root->left = ArrayToBST(arr, start, mid - 1);
        root->right = ArrayToBST(arr, mid + 1, end);

        return root;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    Node* bstRoot = sol.sortedArrayToBST(nums);
    cout << "In-order traversal of the constructed BST: ";
    inorder(bstRoot);
    cout << endl;
    return 0;
}
