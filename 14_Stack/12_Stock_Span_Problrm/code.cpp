#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> calculateSpan(int price[], int n) {
        vector<int> span(n, 1);
        stack<int> st;

        st.push(0); // first day span is always 1

        for (int i = 1; i < n; i++) {
            while (!st.empty() && price[i] >= price[st.top()]) {
                st.pop();
            }
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }

        return span;
    }
};

int main() {
    Solution sol;
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);

    vector<int> result = sol.calculateSpan(price, n);

    cout << "Stock Span: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
