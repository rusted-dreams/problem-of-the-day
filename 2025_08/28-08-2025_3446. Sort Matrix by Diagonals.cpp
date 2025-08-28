// problem - 3446. Sort Matrix by Diagonals
// link - https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // -------------------------------
        // STEP 1: Sort diagonals starting from the first column (bottom-left triangle)
        // Each diagonal begins at (row, 0) and goes down-right until the matrix boundary
        // -------------------------------
        for (int row = 0; row < n; row++) {
            int col = 0; // fixed at the first column
            vector<int> diag;

            // Collect the diagonal elements starting at (row, 0)
            for (int i = 0; i < n - row; i++) {
                diag.push_back(grid[row + i][col + i]);
            }

            // Sort in descending order (rbegin/rend = reverse iterators)
            sort(diag.rbegin(), diag.rend());

            // Place sorted elements back into the same diagonal
            for (int i = 0; i < n - row; i++) {
                grid[row + i][col + i] = diag[i];
            }
        }

        // -------------------------------
        // STEP 2: Sort diagonals starting from the last row (top-right triangle)
        // Each diagonal begins at (row, n-1) and goes up-left until the matrix boundary
        // -------------------------------
        for (int row = n - 2; row >= 0; row--) {
            int col = n - 1; // fixed at the last column
            vector<int> diag;

            // Collect the diagonal elements starting at (row, n-1)
            for (int i = 0; i <= row; i++) {
                diag.push_back(grid[row - i][col - i]);
            }

            // Sort in descending order
            sort(diag.rbegin(), diag.rend());

            // Place sorted elements back into the same diagonal
            for (int i = 0; i <= row; i++) {
                grid[row - i][col - i] = diag[i];
            }
        }

        // Return the fully processed matrix
        return grid;
    }
};


int main() {
    Solution sol;

}