// problem - 781. Rabbits in Forest
// link - https://leetcode.com/problems/rabbits-in-forest/?envType=daily-question&envId=2025-04-20

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        for (int i : answers) {
            if (i == 0) ans++;
            else {
                mpp[i]++;
            }
        }
        for (auto& it : mpp) {
            int color = it.first;
            int freq = it.second;
            while (freq >= color + 1) {
                ans += color + 1;
                freq -= color + 1;
            }
            if (freq) {
                ans += color + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

}