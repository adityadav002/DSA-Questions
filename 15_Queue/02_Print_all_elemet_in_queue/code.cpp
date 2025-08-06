#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;

    for(int i = 1; i< 11; i++){
        q.push(i);
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout <<" Size of q: "<<q.size() << endl;

    cout << endl;

    queue<int> q2;
    for(int i = 11; i < 21; i++){
        q2.push(i);
    }

    int n = q2.size();

    while (n--)
    {
        cout << q2.front() << " ";
        q2.push(q2.front());
        q2.pop();
    }
    cout << endl;
    cout <<" Size of q2: "<<q2.size() << endl;
    
}