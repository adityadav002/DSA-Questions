#include <iostream>
#include <vector>
using namespace std;

void subSumPrint(int arr[], int index, int n, int sum, vector<int>& path, int& count) {
    if (sum == 0) {
        count++;
        cout << "Combination " << count << ": ";
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    if (index == n || sum < 0) return;
    path.push_back(arr[index]);
    subSumPrint(arr, index, n, sum - arr[index], path, count);
    path.pop_back(); 
    subSumPrint(arr, index + 1, n, sum, path, count);
}

int main() {
    int arr[] = {1, 2, 5};
    int target = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> path;
    int count = 0;
    subSumPrint(arr, 0, n, target, path, count);
    cout << "Total combinations: " << count << endl;
    return 0;
}
