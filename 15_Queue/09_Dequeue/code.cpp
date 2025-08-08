#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);

    cout<< dq.front()<<" ";
    cout<< dq.back()<<" ";
    cout<<endl;
    dq.pop_back();
    dq.pop_front();

    cout<< dq.front()<<" ";
    cout<< dq.back()<<" ";
    cout<<endl;
    return 0;
}