#include<iostream>
#include<queue>
#include<vector> 
using namespace std;

class Node 
{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    vector<int> levelOrder(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
        return ans;
    }
};

int main()  
{
    int x, first, second;
    cout << "Enter the root element: ";
    cin >> x;

    Node *root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left child of " << temp->data << " (-1 for NULL): ";
        cin >> first;
        if(first != -1){
            temp->left = new Node(first);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " (-1 for NULL): ";
        cin >> second;
        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }

    Solution obj;
    vector<int> result = obj.levelOrder(root);

    cout << "Level Order Traversal: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
