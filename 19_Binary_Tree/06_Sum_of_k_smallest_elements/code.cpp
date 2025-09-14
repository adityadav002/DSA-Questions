#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void KSum(Node *root, int &sum, int &k) {
    if (!root || k <= 0) return;

    KSum(root->left, sum, k);

    if (k > 0) {
        sum += root->data;
        k--;
    }

    KSum(root->right, sum, k);
}

int sum(Node* root, int k) {
    int total = 0;
    KSum(root, total, k);
    return total;
}

int main() {

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k = 3;
    int result = sum(root, k);
    cout << "Sum of first " << k << " smallest elements: " << result << endl;

    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}


    /*
        Construct the following BST:
              5
             / \
            3   8
           / \
          2   4
         /
        1

        In-order: 1 2 3 4 5 8
    */