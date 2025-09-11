#include <iostream>
#include <algorithm>
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
    
    int Burn(Node *root, int &timer, int target){
        if(!root) return 0;
        if(root->data == target) return -1;
        
        int left = Burn(root->left, timer, target);
        int right = Burn(root->right, timer, target);
        
        if(left < 0){
            timer = max(timer, abs(left)+right);
            return left-1;
        }
        if(right < 0){
            timer = max(timer, abs(right)+left);
            return right-1;
        }
        
        return 1+max(left, right);
    }
    
    void find(Node *root, int target, Node *&BurnNode){
        if(!root) return;
        
        if(root->data == target){
            BurnNode = root;
            return;
        }
        
        find(root->left, target, BurnNode);
        find(root->right, target, BurnNode);
    }
    
    int height(Node *root){
        if(!root) return 0;
        
        return 1+max(height(root->left), height(root->right));
    }
  
    int minTime(Node* root, int target) {
        int timer = 0;
        Burn(root, timer, target);
        
        Node *BurnNode = NULL;
        find(root, target, BurnNode);
        int high = height(BurnNode) - 1;
        
        return max(timer, high);
    }
};

Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    int target = 2;
    Solution sol;
    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the entire tree from target " << target << " is: " << result << endl;
    return 0;
}

   /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */