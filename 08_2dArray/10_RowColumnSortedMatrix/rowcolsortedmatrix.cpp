#include<iostream>
#include<vector>
using namespace std;

int search(vector<vector<int>>& matrix, int target)
{
  int N = matrix.size(), M = matrix[0].size();
  int row = 0, col = M-1;
  while (row < N && col >= 0)
  {
    if(matrix[row][col] == target){
      return 1;
    }
    else if(matrix[row][col] < target){
     row++;
    }
    else{
      col--;
    }
  }
  return 0;
}
int main()
{
   vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 16, 17}      
  };
  int target = 18;

  cout<< " " << search(matrix, target) << endl;

  return 0;
}