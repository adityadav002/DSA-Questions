#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    double prefixSum = 0;
    int start = 0, end = 0, n = arr.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
      prefixSum += arr[end];
      if (end - start + 1 == k)
      {
        if (prefixSum / k >= threshold)
          count++;
        prefixSum -= arr[start++];
      }
      end++;
    }
    return count;
  }
};

int main()
{
  Solution sol;

  // Example test case
  vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
  int k = 3;
  int threshold = 4;

  int result = sol.numOfSubarrays(arr, k, threshold);
  cout << "Number of subarrays of length " << k << " with average >= " << threshold << " is: " << result << endl;

  return 0;
}
