// problem - 2206. Divide Array Into Equal Pairs
// link - https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> freq;
            int n = nums.size();
            for(int i:nums){
                freq[i]++;
            }
            for(auto it : freq) {
                if(it.second&1) return false;
            }
            return true;
        }
    };
    

int main() {
    Solution sol;
    
}