// problem - 1800. Maximum Ascending Subarray Sum
// link - https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSum = (nums[i] > nums[i - 1]) ? currSum + nums[i] : nums[i];
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

}