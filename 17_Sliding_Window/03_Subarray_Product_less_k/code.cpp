#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int product = 1, start = 0, end = 0, n = nums.size(), count = 0;
        while (end < n) {
            product *= nums[end];

            while (product >= k && start <= end) {
                product /= nums[start];
                start++;
            }

            count += (end - start) + 1;
            end++;
        }
        return count;
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
    int result = obj.numSubarrayProductLessThanK(nums, k);

    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}
