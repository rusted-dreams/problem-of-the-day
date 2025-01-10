// link - https://leetcode.com/problems/word-subsets/?envType=daily-question&envId=2025-01-10
// problem - 916. Word Subsets

#include <bits/stdc++.h>
using namespace std;

// explore other optimizations:
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq;
        vector<string> ans;
        for (string word : words2) {
            unordered_map<char, int> freq;
            for (char i : word) {
                freq[i]++;
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        for(string word : words1) {
            unordered_map<char, int> mp1;
            bool universal = true;
            for(char i: word) {
                mp1[i]++;
            }
            for(auto it: maxFreq){
                if(it.second > mp1[it.first]){
                    universal = false;
                    break;
                }
            }
            if(universal) {
                ans.push_back(word);
            }
            universal = true;
        }
        return ans;
    }
};

int main() {
    vector<string> words1 = {"leetcode"};
    vector<string> words2 = {"lo", "eo"};

}