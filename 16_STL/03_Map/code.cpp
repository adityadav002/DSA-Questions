#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> age;

    age["Aditya"] = 25;
    age["Charlie"] = 28;
    age["Bob"] = 30;
    age.insert(make_pair("david", 12));

    for (auto pair : age) {
        cout << pair.first << " is " << pair.second << " years old.\n";
    }

    return 0;
}
