// link - https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
// problem - 1408. String Matching in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // abhi ke liye to brute force hi kiya hai baaki optimise karne ke liye kmp use hoga wo aata nhi to dekhna padega.
    vector<string> stringMatching(vector<string>& words) {
        if(words.empty()) return {};
        vector<string> res;
        for(auto i:words){
            bool flag = false;
            for(auto word:words){
                if(word.find(i) != string::npos && word != i){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};


int main() {
    
}