// problem - 2200. Find All K-Distant Indices in an Array
// link - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (abs(i - j) <= k && nums[j] == key) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

// initial brute with unoptimised space:
// class Solution {
// public:
//     vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//         set<int> st;
//         for(int i=0; i<nums.size(); i++) {
//             for(int j = 0; j<nums.size(); j++) {
//                 if(abs(i-j) <= k && nums[j] == key) st.insert(i);
//             }
//         }
//         vector<int> res(st.begin(), st.end());
//         sort(res.begin(), res.end());
//         return res;
//     }
// };

int main() {
    Solution sol;

}