#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; 
    cout << "Back element: " << q.back() << endl;  
    cout << "Queue size: " << q.size() << endl;     

    q.pop(); // Removes the front element (10)
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Queue size after pop: " << q.size() << endl; 

    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl; 
    }

    // Clear the queue
    while (!q.empty()) {
        q.pop();
    }
    cout << "Queue size after clearing: " << q.size() << endl; 

    return 0;
}