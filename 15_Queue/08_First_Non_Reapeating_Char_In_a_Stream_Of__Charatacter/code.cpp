#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string solve(string A) {
    string B = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for (int i = 0; i < A.size(); i++) {
        char ch = A[i];
        repeated[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && repeated[q.front() - 'a'] > 1)
            q.pop();
        
        if (q.empty()) 
            B += '#';
        else 
            B += q.front();
    }
    return B;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = solve(input);
    cout << "First non-repeating characters stream: " << result << endl;

    return 0;
}
