#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBigInt(string num1, string num2) {
    
    // Make sure num1 is the longer one
    if (num2.size() > num1.size()) swap(num1, num2);

    string result = "";
    int carry = 0, diff = num1.size() - num2.size();

    // Add digits from right to left
    for (int i = num2.size() - 1; i >= 0; i--) {
        int sum = (num1[i + diff] - '0') + (num2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
    }

    // Process remaining digits in num1
    for (int i = diff - 1; i >= 0; i--) {
        int sum = (num1[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) result += (carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "123456789123456789";
    string b = "987654321987654321";
    cout << "Sum: " << addBigInt(a, b) << endl;
    return 0;
}