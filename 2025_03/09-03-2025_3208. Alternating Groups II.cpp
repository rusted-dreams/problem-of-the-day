// problem - 3208. Alternating Groups II
// link - https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int l = 0, r = k - 1, res = 0, count = 0;
    
            // Initialize count of adjacent same-colored tiles in the first window
            for(int i = 0; i < k - 1; i++) {
                if(colors[i] == colors[i + 1]) count++;
            }
    
            // Slide the window across the circular array
            while(l < n) {
                if(count == 0) res++; // If no adjacent same colors, it's a valid group
    
                // Remove leftmost element's contribution before shifting window
                if(colors[l] == colors[(l + 1) % n]) count--;
                l++;
    
                // Add rightmost element's contribution after shifting window
                if(colors[r % n] == colors[(r + 1) % n]) count++;
                r++;
            }
            
            return res;
        }
    };
    

int main() {
    Solution sol;
    
}