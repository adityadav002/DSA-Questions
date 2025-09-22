#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* BST(int post[], int &index, int lower, int upper) {
    if (index < 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node *root = new Node(post[index--]);
    
    root->right = BST(post, index, root->data, upper);
    root->left = BST(post, index, lower, root->data);
    
    return root;
}

Node* constructTree(int post[], int size) {
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int postorder[] = {1, 7, 5, 12, 10, 8};
    int size = sizeof(postorder) / sizeof(postorder[0]);

    Node* root = constructTree(postorder, size);

    cout << "Inorder Traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
