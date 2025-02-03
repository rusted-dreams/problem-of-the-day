// problem - 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// link - https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1, increasing = 1, decreasing = 1;

        for(int i = 1; i < nums.size(); i++) {
            // Check for increasing sequence
            if(nums[i] > nums[i-1]) increasing++;
            else increasing = 1;

            // Check for decreasing sequence
            if(nums[i] < nums[i-1]) decreasing++;
            else decreasing = 1;

            // Update max length
            maxi = max(maxi, max(increasing, decreasing));
        }
        return maxi;
    }
};

int main() {
    
}