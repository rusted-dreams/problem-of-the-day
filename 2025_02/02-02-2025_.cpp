// problem - 1752. Check if Array Is Sorted and Rotated
// link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Mera waala solution:
    // bool check(vector<int>& nums) {
    //     bool rotated = false;
    //     for(int i=1; i<nums.size(); i++){
    //         if(nums[i] < nums[i-1] && rotated) return false;
    //         if(nums[i] < nums[i-1] && !rotated) rotated = true;
    //         if(nums[i] > nums[i-1] && rotated && nums[i] > nums[0]) return false;
    //         if(rotated && nums[i] > nums[0]) return false;
    //     }
    //     return true;
    // }

    // alternate solution:
    bool check(vector<int> &nums) {
        // logic:
        // agar array rotate hua hai, to poore arr mein 2 sorted arr honge - (1 rotate hone se pehle and dusra rotate hone ke baad). agar 2 se jaada sorted sub arr hain to return false.
        int count = 0; // how many sorted sub arrays are there in the given arr.
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[(i+1)%nums.size()]) count++;
        }
        // if(nums[nums.size()-1]> nums[0]){
        //     count++;
        // }
        // if(count<=1) return true;
        // else return false;
        return count<=1;
    }
};

int main() {
    Solution sol;
     
}