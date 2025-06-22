#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> arr, int n)
{
    // Decrease by 1.
    for(int i = 0; i < n; i++) {
        arr[i]--;
    }

    // Occurrence.
    for(int i = 0; i < n; i++) {
        arr[arr[i] % n] += n;
    }

    vector<int> ans(2);

    for(int i = 0; i < n; i++) {
      // for repeated.
        if(arr[i] / n == 2) {
            ans[0] = i + 1;
        } 
        // for missing.
        else if(arr[i] / n == 0) {
            ans[1] = i + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> result = solve(arr, n);

    cout << "solution is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
