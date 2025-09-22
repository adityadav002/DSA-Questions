#include <iostream>
#include <climits>
using namespace std;

class Solution {
  public:
    void BST(int arr[], int &index, int lower, int upper, int N){
        if(index == N || arr[index] < lower || arr[index] > upper)
            return;
        
        int value = arr[index++];
        BST(arr, index, lower, value, N);  
        BST(arr, index, value, upper, N);  
    }
    
    int canRepresentBST(int arr[], int N) {
        int index = 0;
        BST(arr, index, INT_MIN, INT_MAX, N);
        return index == N;
    }
};

int main() {
    Solution sol;

    int arr1[] = {10, 5, 1, 7, 40, 50};
    int arr2[] = {10, 5, 1, 7, 40, 30};

    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int N2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "arr1 is " << (sol.canRepresentBST(arr1, N1) ? "a valid" : "an invalid") << " BST preorder" << endl;
    cout << "arr2 is " << (sol.canRepresentBST(arr2, N2) ? "a valid" : "an invalid") << " BST preorder" << endl;

    return 0;
}
