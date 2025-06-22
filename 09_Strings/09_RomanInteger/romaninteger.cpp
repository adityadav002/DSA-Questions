#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Roman to Integer
    int romanToInt(string s) {
        int sum = 0, index = 0;
        while (index < s.size() - 1) {
            if (num(s[index]) < num(s[index + 1])) {
                sum -= num(s[index]);
            } else {
                sum += num(s[index]);
            }
            index++;
        }
        sum += num(s[index]); 
        return sum;
    }

    // Integer to Roman 
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        int i = 0;

        while (num > 0) {
            if (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            } else {
                i++;
            }
        }
        return result;
    }

private:
    int num(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main() {
    Solution sol;

    // Integer to Roman
    int number = 1994;
    string roman = sol.intToRoman(number);
    cout << "Integer to Roman (" << number << "): " << roman << endl;

    // Roman to Integer
    string romanStr = "MCMXCIV";
    int intValue = sol.romanToInt(romanStr);
    cout << "Roman to Integer (" << romanStr << "): " << intValue << endl;

    return 0;
}
