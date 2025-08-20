#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double prefixSum = 0, ans = INT_MIN;
        int start = 0, end = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            prefixSum += nums[end];
            if (end - start + 1 == k) {
                ans = max(ans, prefixSum);
                prefixSum -= nums[start++];
            }
            end++;
        }

        double result = ans / k;
        return result;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double maxAverage = sol.findMaxAverage(nums, k);
    cout << "Maximum average of subarray of length " << k << " is: " << maxAverage << endl;

    return 0;
}
