#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.push_front(10);
    l.push_front(5);

    for(auto i = l.begin(); i != l.end(); i++){
        cout<<*i<<" ";
    }

    return 0;
}