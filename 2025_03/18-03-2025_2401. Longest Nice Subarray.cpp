// problem - 2401. Longest Nice Subarray
// link - https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size();
            int res = 1;
            int l = 0, r=0;
            int mask = nums[0];
            while(r < n-1) {
                r++;
                while(mask & nums[r]){
                    mask = (~nums[l]) & mask;
                    l++;
                }
                res = max(res, r - l + 1);
                mask = mask | nums[r];
            }
            return res;
        }
    };
    
    
    // class Solution {
    // public:
    //     int longestNiceSubarray(vector<int>& nums) {
    //         int n = nums.size();
    //         int l = 0, r = 0;
    //         int res = 1;
    //         // bits[i] will count how many numbers in the current window have the i-th bit set.
    //         vector<int> bits(32, 0);
            
    //         // Initialize window with the first number.
    //         {
    //             int num = nums[0];
    //             int count = 0;
    //             while(num) {
    //                 if(num & 1)
    //                     bits[count]++;
    //                 count++;
    //                 num = num >> 1;
    //             }
    //         }
            
    //         // Helper lambda to compute the current combined mask (prev)
    //         auto getMask = [&]() -> int {
    //             int mask = 0;
    //             for (int i = 0; i < 32; i++) {
    //                 if(bits[i] > 0)
    //                     mask |= (1 << i);
    //             }
    //             return mask;
    //         };
            
    //         // Process the rest of the array
    //         while(r < n - 1) {
    //             r++;
    //             int prev = getMask();
    //             // If adding nums[r] would cause a conflict,
    //             // remove elements from the left until no conflict.
    //             while ((nums[r] & prev) != 0 && l < r) {
    //                 int rem = nums[l];
    //                 int count = 0;
    //                 while(rem) {
    //                     if(rem & 1)
    //                         bits[count]--;
    //                     count++;
    //                     rem = rem >> 1;
    //                 }
    //                 l++;
    //                 prev = getMask();
    //             }
                
    //             // Now it's safe to add nums[r] into the window.
    //             int add = nums[r];
    //             int count = 0;
    //             while(add) {
    //                 if(add & 1)
    //                     bits[count]++;
    //                 count++;
    //                 add = add >> 1;
    //             }
                
    //             res = max(res, r - l + 1);
    //         }
            
    //         return res;
    //     }
    // };
    
    

int main() {
    Solution sol;
    
}