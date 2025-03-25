// problem - 3394. Check if Grid can be Cut into Sections
// link - https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Sort rectangles by their left x-coordinate (rectangles[i][0])
        sort(rectangles.begin(), rectangles.end(), [ ](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });

        int count = 1;  // Count of distinct vertical segments
        pair<int, int> curr = { rectangles[0][0], rectangles[0][2] };  // Track the current segment (left x, right x)

        // Iterate over rectangles to determine vertical segments
        for (int i = 1; i < rectangles.size(); i++) {
            pair<int, int> rec = { rectangles[i][0], rectangles[i][2] };  // Current rectangle's left and right x-coordinates

            if (rec.first < curr.second) {
                // If overlapping, merge the intervals by extending the right boundary
                curr.second = max(curr.second, rectangles[i][2]);
            }
            else {
                // Otherwise, start a new segment
                count++;
                curr = { rectangles[i][0], rectangles[i][2] };
            }
        }

        // If at least 3 vertical segments are found, return true
        if (count >= 3) return true;

        count = 1;  // Reset count for horizontal check

        // Sort rectangles by their bottom y-coordinate (rectangles[i][1])
        sort(rectangles.begin(), rectangles.end(), [ ](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });

        curr = { rectangles[0][1], rectangles[0][3] };  // Track the current segment (bottom y, top y)

        // Iterate over rectangles to determine horizontal segments
        for (int i = 1; i < rectangles.size(); i++) {
            pair<int, int> rec = { rectangles[i][1], rectangles[i][3] };  // Current rectangle's bottom and top y-coordinates

            if (rec.first < curr.second) {
                // If overlapping, merge the intervals by extending the top boundary
                curr.second = max(curr.second, rectangles[i][3]);
            }
            else {
                // Otherwise, start a new segment
                count++;
                curr = { rectangles[i][1], rectangles[i][3] };
            }
        }

        // Return true if at least 3 horizontal segments are found, otherwise return false
        return count >= 3;
    }
};


int main() {
    Solution sol;

}