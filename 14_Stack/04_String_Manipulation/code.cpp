#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string arr[] = {"ab", "aa", "aa", "bcd", "ab"};
    stack<string> s;
    for(int i=0; i<5; i++){
        if(s.empty())
        s.push(arr[i]);
        else if(s.top() == arr[i]){
            s.pop();
        }
        else{
            s.push(arr[i]);
        }
    }

    cout << s.size() << endl;
    return 0;
}