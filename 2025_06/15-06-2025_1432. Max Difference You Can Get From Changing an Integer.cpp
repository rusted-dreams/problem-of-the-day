// problem - 1432. Max Difference You Can Get From Changing an Integer
// link - https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/?envType=daily-question&envId=2025-06-15

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);   // Convert original number to string for manipulation
        string str2 = str;             // Copy to use for minimizing later

        // -------- Maximize the number --------
        char x = '9';
        for (char ch : str) {
            if (ch != '9') {            // Find first digit that's not 9
                x = ch;
                break;
            }
        }
        replace(str.begin(), str.end(), x, '9');  // Replace all occurrences with 9

        // -------- Minimize the number --------
        if (str2[0] != '1') {                     // If first digit is not 1
            x = str2[0];
            replace(str2.begin(), str2.end(), x, '1');  // Replace it with 1
        }
        else {
            char x = '1';
            for (int i = 1; i < str2.length(); i++) {
                if (str2[i] != '0' && str2[i] != '1') {  // Find first digit (after index 0) not 0 or 1
                    x = str2[i];
                    break;
                }
            }
            if (x != '1') replace(str2.begin(), str2.end(), x, '0');  // Replace with 0 to minimize
        }

        return stoi(str) - stoi(str2);  // Return the difference between max and min versions
    }
};

int main() {
    Solution sol;

}