#include<iostream>
#include<stack>
using namespace std;

int main()
{
    char arr[5] = {'a', 's', 'd', 'f', 'g'};
    stack <char> s;
    for( int i=0; i<5; i++)
    {
        s.push(arr[i]);
    }
    for( int i=0; i<5; i++)
    {
        arr[i] = s.top();
        s.pop();
    }
    for( int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}