#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<string, int> person;
    person.first = "Aditya";
    person.second = 21;
    // person = make_pair("Yadav", 21);
    cout<<"Name: "<<person.first<<", "<<"Age: "<<person.second<<endl;

    pair<string, pair<int, int>>student;
    student.first = "Aditya";
    student.second.first = 50;
    student.second.second = 45;
    cout<<"Name: "<<student.first<<", "<<"Maths: "<<student.second.first<<", "<<"English: "<<student.second.second<<endl;
}