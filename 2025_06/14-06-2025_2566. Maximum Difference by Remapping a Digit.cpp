// problem - 2566. Maximum Difference by Remapping a Digit
// link - https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/?envType=daily-question&envId=2025-06-14

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};

// unoptimal using vectors:
// class Solution {
// public:
//     int minMaxDifference(int num) {
//         int x = num;
//         int count = 0;
//         vector<int> digits;
//         while(x) {
//             int digit = x%10;
//             x = x / 10;
//             digits.push_back(digit);
//         }

//         reverse(digits.begin(), digits.end());
//         int high = -1;
//         int low = digit[0];
//         for(int i=0; i<digits.size(); i++) {
//             if(digits[i] < 9 && high == -1) {
//                 high = digits[i];
//             }
//         }
//         int maxi = 0;
//         int mini = 0;
//         for(int i=0; i<digits.size(); i++) {
//             if(digits[i] == high) {
//                 maxi = maxi * 10 + 9;
//             }
//             else {
//                 maxi = maxi * 10 + digits[i];
//             }
//         }
//         for(int i=0; i<digits.size(); i++) {
//             if(digits[i] == low) {
//                 mini = mini * 10;
//             }
//             else {
//                 mini = mini * 10 + digits[i];
//             }
//         }
//         return maxi - mini;

//     }
// };

int main() {
    Solution sol;

}