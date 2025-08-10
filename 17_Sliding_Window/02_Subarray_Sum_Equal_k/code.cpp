#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int PrefixSum = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            PrefixSum += nums[i];
            if (m.count(PrefixSum - k)) {
                total += m[PrefixSum - k];
            }
            m[PrefixSum]++;
        }
        return total;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
