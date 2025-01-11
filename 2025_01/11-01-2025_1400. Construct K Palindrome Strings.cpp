// link - https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11
// problem - 1400. Construct K Palindrome Strings

#include <bits/stdc++.h>
using namespace std;


// we need to find the total no. characters in the string that appears odd times.
// if the no. of odd times appearing chars is greater than k. then theres no way possible to form k palindromes using all chars of s.
// even appearing chars can be adjusted anywhere in any palindrome without any change. its the odd ones that we need to take care of.
bool canConstruct(string s, int k) {
    // edge cases:
    if (k == s.length()) return true;
    if (k > s.length()) return false;
   
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }
    
    // count the chars appearing odd times.
    int oddCount = 0;
    for (int i : freq) {
        if (i % 2 == 1) oddCount++;
    }
    
    if (oddCount <= k) return true;
    else return false;

}
int main() {

}