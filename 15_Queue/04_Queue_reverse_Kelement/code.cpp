#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;
    int k = 3;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }

    int n = q.size();

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(n--){
        q.push(q.front());
        q.pop();
    }

    n = q.size();

    while (n--)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }

    return 0;
}