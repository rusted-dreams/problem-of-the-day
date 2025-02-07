// problem - 3160. Find the Number of Distinct Colors Among the Balls
// link - https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/?envType=daily-question&envId=2025-02-07

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Map to store the current color for each element (identified by its id)
        unordered_map<int, int> colors;
        // Map to keep track of the frequency of each color
        unordered_map<int, int> freq;
        // Vector to store the number of distinct colors after each query
        vector<int> res;
        
        // Process each query
        for (auto& query : queries) {
            int id = query[0];      // Element identifier
            int newColor = query[1]; // Color to assign
            
            // If the element already exists in our mapping
            if (colors.find(id) != colors.end()) {
                int oldColor = colors[id];
                // Only update frequencies if the color actually changes
                if (newColor != oldColor) {
                    // Decrement the frequency of the old color
                    freq[oldColor]--;
                    // If the old color's frequency drops to 0, remove it from the frequency map
                    if (freq[oldColor] == 0)
                        freq.erase(oldColor);
                    // Increment the frequency of the new color
                    freq[newColor]++;
                }
                // Update the element's color regardless of whether it changed
                colors[id] = newColor;
            }
            // If the element is new, add it and update the frequency count for its color
            else {
                colors[id] = newColor;
                freq[newColor]++;
            }
            // Append the current count of distinct colors (size of the frequency map) to the result
            res.push_back(freq.size());
        }
        // Return the results after processing all queries
        return res;
    }
};


int main() {
    Solution sol;
    
}