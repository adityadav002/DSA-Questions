#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(), M = matrix[0].size();
        int row_index, col_index, start = 0, end = N * M - 1, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            row_index = mid / M;
            col_index = mid % M;

            if (matrix[row_index][col_index] == target) {
                return 1;
            }
            else if (matrix[row_index][col_index] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 16, 17}      
    };
    
    int target = 10;
    
    cout << solution.searchMatrix(matrix, target) << endl;
    
    return 0;
}
