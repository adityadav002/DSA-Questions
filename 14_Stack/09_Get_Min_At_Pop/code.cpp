#include <iostream>
#include <stack>
#include <algorithm> 
using namespace std;

stack<int> _push(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            st.push(arr[i]);
        else
            st.push(min(arr[i], st.top()));
    }
    return st;
}

void _getMinAtPop(stack<int> s)
{
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 5, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    stack<int> minStack = _push(arr, n);

    cout << "Minimum at each pop: ";
    _getMinAtPop(minStack);

    return 0;
}
