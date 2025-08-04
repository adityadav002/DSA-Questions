#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<long long> nextSmallerElement(vector<long long>& arr, int n) {
        vector<long long> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<long long> arr = {4, 5, 2, 25};
    int n = arr.size();

    vector<long long> result = sol.nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
