#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int x = 2;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stack<int> tempStack;
    while (!s.empty())
    {
        tempStack.push(s.top());
        s.pop();
    }

    s.push(x);
    while(!tempStack.empty()){
        s.push(tempStack.top());
        tempStack.pop();
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}