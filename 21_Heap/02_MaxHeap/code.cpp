#include <iostream>
using namespace std;

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n)
{
    // step down approach
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 25, 5, 40, 35};
    buildMaxHeap(arr, 7);
    cout << "Max Heap array: ";
    printHeap(arr, 7);
}

// Output: Max Heap array: 40 25 35 10 5 30 20
        //         40
        //       /    \
        //      25     35
        //     /  \    /  \
        //    10   5  30   20
