// link - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04
// problem - 1930. Unique Length-3 Palindromic Subsequences


#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.length();
    unordered_set<char> letters;
    for (int i = 0; i < n; i++) {
        letters.insert(s[i]);
    }

    int result = 0;
    int left_idx = -1;
    int right_idx = -1;

    for (char letter : letters) {

        //find the left idx
        for (int i = 0; i < n; i++) {
            if (s[i] == letter) {
                left_idx = i;
                break;
            }
        }

        // find the right idx
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == letter) {
                right_idx = i;
                break;
            }
        }

        // all the middle elements in the set;
        unordered_set<char> st;
        for (int i = left_idx + 1; i < right_idx; i++)
            st.insert(s[i]);

        // total palindromes by that char is size of the set:
        result += st.size();
    }
    return result;
}
int main() {

}