#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        long long int total = 0;
        unordered_map<long long int, long long int> m;
        long long int PrefixSum = 0;
        m[0] = 1;

        for (int i = 0; i < n; i++) {
            PrefixSum += arr[i];

            if (m.count(PrefixSum)) {
                total += m[PrefixSum];
            }

            m[PrefixSum]++;
        }

        return total;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<long long int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    long long int result = obj.findSubarray(arr, n);

    cout << "Number of subarrays with sum 0: " << result << endl;

    return 0;
}
