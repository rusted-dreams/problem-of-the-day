// problem - 2560. House Robber IV
// link - https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& nums, int capability, int k){
        int n = nums.size();
        int stealCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i] <= capability){
                stealCount++;
                i++;
                if(stealCount == k) return true; 
            }
        }
        return false;  
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        int mid;
        while( start <= end) {
            mid = start + (end-start)/2;
            if(isPossible(nums, mid, k)){
                end = mid - 1;
            }
            else start = mid+1;
        }
        return start;
    }
};

int main() {
    Solution sol;
    
}