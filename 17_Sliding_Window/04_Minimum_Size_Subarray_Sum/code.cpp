#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int total = INT_MAX, start = 0, end = 0, sum = 0, n = nums.size();
        while (end < n)
        {
            sum += nums[end];
            while (sum >= target)
            {
                total = min(total, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return total == INT_MAX ? 0 : total;
    }
};

int main()
{
    Solution sol;

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum length of a subarray with sum >= " << target << " is: " << result << endl;

    return 0;
}
