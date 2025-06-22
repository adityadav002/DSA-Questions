#include<iostream>
#include<algorithm>
using namespace std;

void flp(int arr[], int n, int key, int& first, int& last) {
    first = -1;
    last = -1;

    int start = 0, end = n - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1; 
        }
    }

    start = 0;
    end = n - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1; 
        }
    }
}

int main() {
    int n;
    cout << "Enter Array Size: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter Key Element: ";
    cin >> key;

    int first, last;
    flp(arr, n, key, first, last); 
    cout << "First Position: " << first << endl;
    cout << "Last Position: " << last << endl;

    return 0;
}
