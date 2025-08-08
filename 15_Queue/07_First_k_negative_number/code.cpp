#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int display(queue<int> q){
    while(!q.empty()){
        if(q.front() < 0)
             return q.front();
        q.pop();
    }
    return 0;
}

int main(){
    int arr[] = {2,-3,-1,-5,6,7,8,-8};
    int n = 8, k = 3;

    queue<int> q;
    vector<int> ans;
    for(int i=0; i<k-1; i++)
        q.push(arr[i]);
    
    for(int i=k-1; i<n; i++){
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
    }
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    return 0;
}

