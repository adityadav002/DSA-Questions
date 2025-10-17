#include <iostream>
using namespace std;

class maxHeap {
    int* arr;
    int size;
    int total_size;

public:
    maxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert into heap
    void insert(int val) {
        if (size == total_size) {
            cout << "Heap overflow" << endl;
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        // Heapify up
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << val << " is inserted in the heap" << endl;
    }

    // Heapify down from given index
    void Heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    // Delete max (root) from heap
    void Delete() {
        if (size == 0) {
            cout << "Heap Underflow" << endl;
            return;
        }

        cout << arr[0] << " Deleted from the heap" << endl;

        arr[0] = arr[size - 1];
        size--;

        if (size > 0) {
            Heapify(0);
        }
    }

    // View the max element without removing
    int peek() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    // Print all elements in heap
    void print() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~maxHeap() {
        delete[] arr;
    }
};

// Main function to test heap
int main() {
    maxHeap h1(6);

    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.insert(31);

    h1.print();

    cout << "Max element is: " << h1.peek() << endl;

    h1.Delete();
    h1.print();

    h1.Delete();
    h1.print();

    int top = h1.peek();
    cout<<"Larget element of the heap: "<<top;
    return 0;
}
