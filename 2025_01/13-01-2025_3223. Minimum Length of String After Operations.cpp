// problem - 3223. Minimum Length of String After Operations
// link - https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13

#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }
    int res = 0;
    for (int i : freq) {
        res += i%2==0? 2:1;
    }
    return res;
}

int main() {

}