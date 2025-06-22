#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Mark vowels and count them
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        // Collect sorted vowels
        string vowel;

        for (int i = 0; i < 26; i++) {
            char c = 'A' + i;
            while (upper[i]--) vowel += c;
        }

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (lower[i]--) vowel += c;
        }

        // Replace '#' with sorted vowels
        int first = 0, second = 0;
        while (second < vowel.size()) {
            if (s[first] == '#') {
                s[first] = vowel[second];
                second++;
            }
            first++;
        }

        return s;
    }
};

int main() {
    Solution sol;
    
    string input1 = "lEetcOde";
    string input2 = "beautiful";

    cout << "Original: " << input1 << " Sorted vowels: " << sol.sortVowels(input1) << endl;
    cout << "Original: " << input2 << " Sorted vowels: " << sol.sortVowels(input2) << endl;

    return 0;
}
