#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int n = q.size();

    while (n--)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
    
}