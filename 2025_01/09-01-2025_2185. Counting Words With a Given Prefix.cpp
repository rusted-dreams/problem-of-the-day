// problem - 2185. Counting Words With a Given Prefix
// link - https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        bool prefix = true;
        for (auto word:words) {
            if(word.length()>= pref.length()) {
                for(int i = 0; i<pref.length(); i++){
                    if (word[i] != pref[i]){
                        prefix = false;
                        break;
                    }
                }
                prefix?ans++:ans;
                prefix = true;
            }
        }
        return ans;
    }
};

int main() {
    
}