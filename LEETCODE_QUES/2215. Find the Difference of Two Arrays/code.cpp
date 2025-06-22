#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    const int OFFSET = 1000;
    const int SIZE = 2001;

    vector<int> count1(SIZE, 0);
    vector<int> count2(SIZE, 0);

    for (int i = 0; i < nums1.size(); ++i)
      count1[nums1[i] + OFFSET] = 1;

    for (int i = 0; i < nums2.size(); ++i)
      count2[nums2[i] + OFFSET] = 1;

    vector<int> n1, n2;

    for (int i = 0; i < nums1.size(); ++i)
    {
      int idx = nums1[i] + OFFSET;
      if (count1[idx] == 1 && count2[idx] == 0)
      {
        n1.push_back(nums1[i]);
        count1[idx] = 0;
      }
    }

    for (int i = 0; i < nums2.size(); ++i)
    {
      int idx = nums2[i] + OFFSET;
      if (count2[idx] == 1 && count1[idx] == 0)
      {
        n2.push_back(nums2[i]);
        count2[idx] = 0;
      }
    }

    return {n1, n2};
  }
};

int main()
{
  Solution solution;

  // Example input
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {2, 4, 6};

  // Get the result
  vector<vector<int>> result = solution.findDifference(nums1, nums2);

  // Print the output
  cout << "[";
  for (int i = 0; i < result.size(); ++i)
  {
    cout << "[";
    for (int j = 0; j < result[i].size(); ++j)
    {
      cout << result[i][j];
      if (j < result[i].size() - 1)
        cout << ", ";
    }
    cout << "]";
    if (i < result.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;

  return 0;
}
