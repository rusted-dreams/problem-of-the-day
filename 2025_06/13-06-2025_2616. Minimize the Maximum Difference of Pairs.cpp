// problem - 2616. Minimize the Maximum Difference of Pairs
// link - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/?envType=daily-question&envId=2025-06-13

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Counts how many pairs (i, i+1) have difference <= diff
    int countPairs(vector<int>& nums, int diff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= diff) {
                count++;  // valid pair found
                i++;      // skip the next element as it's already paired
            }
            i++;          // move to the next index
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());  // sort to make adjacent pairing optimal
        int n = nums.size();
        int start = 0;                   // minimum possible difference
        int end = nums[n - 1] - nums[0];   // maximum possible difference (range)

        // Binary search to find the minimum max difference that allows at least p valid pairs
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count = countPairs(nums, mid);  // count how many valid pairs with diff <= mid

            if (count >= p) {
                end = mid - 1;  // try to minimize further
            }
            else {
                start = mid + 1; // not enough pairs, increase allowed difference
            }
        }
        return start;  // lowest max difference that forms at least p pairs
    }
};


int main() {
    Solution sol;

}