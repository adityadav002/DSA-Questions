#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;

        // next smallest to right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // next smallest to left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        // calculate max area
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample test case
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    int result = sol.largestRectangleArea(heights);
    
    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}
