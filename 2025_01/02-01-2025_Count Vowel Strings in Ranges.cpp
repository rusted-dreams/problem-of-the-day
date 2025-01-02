// problem link - https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02
// 2559. Count Vowel Strings in Ranges

#include <bits/stdc++.h>
using namespace std;

// brute force to mai khud kar liya tha par optimise karne ke liye gpt ka help liya.
class Solution {
    bool helper(string str) {
        char first = str.front();
        char last = str.back();
        return ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') && (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u'));
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        // create a prefixsum arr. which stores the count of words till index i that start and end with vovel.
        // this optimization makes the solution in O(n).
        vector<int> prefixSum(words.size());
        int prefix = 0;
        for (int i = 0; i < words.size(); i++) {
            if (helper(words[i])) prefix++;
            prefixSum[i] = prefix;
        }

        // the ans for each query is simply the difference of prefixSum[end] and prefixSum[start].
        for (int i = 0; i < n; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans[i] = prefixSum[end] - (start > 0 ? prefixSum[start - 1] : 0);;
        }
        return ans;

    }
};


int main() {

}