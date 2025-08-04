#include<iostream>
#include<stack>
using namespace std;

bool check(string str)
{
    stack<char> st;
    for(int i=0; i<str.size() ;i++)
    {
        if(str[i] == '(')
        st.push(str[i]);
        else{
            if(st.empty())
            return 0;
            else
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "((()))";
    cout<<check(s) <<endl;
    return 0;
}