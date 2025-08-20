
#include <iostream>
#include <vector>
#include <numeric> // For accumulate
using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (leftSum == totalSum - leftSum - nums[i])
        return i;
      leftSum += nums[i];
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 7, 3, 6, 5, 6};

  int pivot = sol.pivotIndex(nums);

  if (pivot != -1)
    cout << "Pivot index is: " << pivot << endl;
  else
    cout << "No pivot index found." << endl;

  return 0;
}
