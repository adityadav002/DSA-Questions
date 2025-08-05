#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>>& m, int n)
    {
        stack<int> st;
        for(int i=n-1; i>=0; i--)
            st.push(i);

        int first, second;

        while(st.size() > 1)
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();

            if(m[first][second] && !m[second][first])
                st.push(second);
            else if(m[second][first] && !m[first][second])
                st.push(first);
            // if both know each other or neither knows the other, discard both
        }

        if(st.empty())
            return -1;

        int num = st.top();
        st.pop();

        int row = 0, col = 0;
        for(int i = 0; i < n; i++)
        {
            row += m[num][i];
            col += m[i][num];
        }

        return (row == 0 && col == n - 1) ? num : -1;
    }
};

int main()
{
    Solution sol;

    // Sample matrix:
    // Person 0 knows 1 and 2
    // Person 1 knows 2
    // Person 2 knows nobody
    vector<vector<int>> m = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int n = m.size();
    int result = sol.celebrity(m, n);

    if (result == -1)
        cout << "There is no celebrity in the party." << endl;
    else
        cout << "Celebrity is person number: " << result << endl;

    return 0;
}
