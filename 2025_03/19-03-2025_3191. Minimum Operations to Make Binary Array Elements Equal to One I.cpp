// problem - 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// link - https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l = 0;
        int r = 2;
        int n = nums.size();
        int count = 0;
        while (r < n) {
            if (nums[l] == 0) {
                count++;
                nums[l] = 1;
                nums[l + 1] = !nums[l + 1];
                nums[l + 2] = !nums[l + 2];
            }
            l++;
            r++;
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0) return -1;
        else return count;
    }
};

int main() {
    Solution sol;

}