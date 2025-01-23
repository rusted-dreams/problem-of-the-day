// problem - 1267. Count Servers that Communicate
// link - https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23

#include <bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> rowCount(rows, 0), colCount(cols, 0);

    // Count servers in each row and column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    // Count servers that can communicate
    int ans = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                ans++;
            }
        }
    }

    return ans;
}
int main() {

}