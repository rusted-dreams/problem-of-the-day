// problem - 2661. First Completely Painted Row or Column
// link - https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20

#include <bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    // Create a map to store the index of each number in the `arr` vector.
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = i; // Map the value in `arr` to its index.
    }

    // Initialize `minIndex` to the maximum possible value (last index of `arr`).
    int minIndex = arr.size() - 1;

    // Check for the first fully painted row:
    for (int i = 0; i < mat.size(); i++) { // Iterate over each row of the matrix.
        int paintedIdx = 0; // Track the maximum index of painted cells in the current row.
        for (int j = 0; j < mat[0].size(); j++) { // Iterate over each element in the row.
            int idx = mp[mat[i][j]]; // Get the index of the current element from `arr`.
            paintedIdx = max(paintedIdx, idx); // Update the maximum painted index.
        }
        minIndex = min(minIndex, paintedIdx); // Update the global minimum index.
    }

    // Check for the first fully painted column:
    for (int i = 0; i < mat[0].size(); i++) { // Iterate over each column of the matrix.
        int paintedIdx = 0; // Track the maximum index of painted cells in the current column.
        for (int j = 0; j < mat.size(); j++) { // Iterate over each element in the column.
            int idx = mp[mat[j][i]]; // Get the index of the current element from `arr`.
            paintedIdx = max(paintedIdx, idx); // Update the maximum painted index.
        }
        minIndex = min(minIndex, paintedIdx); // Update the global minimum index.
    }

    // Return the smallest index at which a row or column is fully painted.
    return minIndex;
}


int main() {

}