// problem - 2033. Minimum Operations to Make a Uni-Value Grid
// link - https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2025-03-26

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int mid = vec[vec.size() / 2];
        int res = 0;
        for (int i : vec) {
            if (abs(i - mid) % x) return -1;
            res += abs(i - mid) / x;
        }
        return res;

    }
};

int main() {
    Solution sol;

}