// link- https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03
// 2270. Number of Ways to Split Array



#include <bits/stdc++.h>
using namespace std;

// hurrayyyy did it without any help but theres space complexity optimization scope like. 
// I dont need to store the left sum and right sum into vectors.
// int waysToSplitArray(vector<int>& nums) {
//     int n = nums.size();
//     vector<long long> leftSum(n-1);
//     vector<long long> rightSum(n-1);
//     int res = 0;

//     leftSum[0]  = nums[0];
//     for(int i=1; i<leftSum.size(); i++) {
//         leftSum[i] = leftSum[i-1] + nums[i];
//     }
//     rightSum[rightSum.size()-1] = nums[n-1];
//     for(int i=rightSum.size()-2; i>=0; i--) {
//         rightSum[i] = rightSum[i+1]+nums[i+1];
//     }
//     for (int i=0; i<leftSum.size(); i++) {
//         if(leftSum[i]>=rightSum[i]) res++;
//     }
//     return res;
// }


// optimized for O(1) space complexity:
int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    long long totalSum = 0, leftSum = 0;
    int res = 0;
    for (int i : nums) {
        totalSum += i;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        leftSum += nums[i];
        long long rightSum = totalSum - leftSum;
        if (leftSum >= rightSum) res++;
    }
    return res;
}


int main() {
    vector<int> nums = { 10, 4, -8, 7 };
    int ans = waysToSplitArray(nums);
    cout << ans << endl;
}