// problem - 2364. Count Number of Bad Pairs
// link - https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   long long countBadPairs(vector<int>& nums) {
       // Maps (nums[i]-i) difference to its frequency
       unordered_map<int, int> freq;
       int n = nums.size();
       long long ans = 0;
       
       for(int i=0; i<n; i++) {
           int diff = nums[i]-i;
           // Total no. of pairs ith element will form with previous elements
           int totalPairs = i;

           // Number of good pairs with same difference
           int goodPairs = freq[diff];

           // Add bad pairs to answer
           ans += totalPairs-goodPairs;

           // Update frequency of current difference
           freq[diff]++;
       }
       return ans;
   }
};

// // Brute Force Approach - O(n²) TLE
// class Solution {
// public:
//    long long countBadPairs(vector<int>& nums) {
//        int n = nums.size();
//        long long countBad = 0;
//        for(int i=0; i<n-1; i++){
//            for(int j = i+1; j<n; j++) {
//                if(j-i != nums[j] - nums[i]) countBad++;
//            }
//        }
//        return countBad;
//    }
// };

int main() {
    Solution sol;
    
}