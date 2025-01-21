// problem - 2017. Grid Game
// link https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21

#include <bits/stdc++.h>
using namespace std;

// all depends on ki robot 1 neeche kon se column par aata hai.
long long gridGame(vector<vector<int>>& grid) {
    long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL); //O(col)

    long long secondRowRemainSum = 0;

    long long minimizedRobot2Sum = LONG_LONG_MAX;

    for (int Robot1Col = 0; Robot1Col < grid[0].size(); Robot1Col++) { //O(col);
        //Robot1 took this strategy
        firstRowRemainSum -= grid[0][Robot1Col];

        //Robot2 will try to do best after Robot1 has taken the above strategy
        long long bestOfRobot2 = max(firstRowRemainSum, secondRowRemainSum);

        minimizedRobot2Sum = min(minimizedRobot2Sum, bestOfRobot2);

        secondRowRemainSum += grid[1][Robot1Col];
    }

    return minimizedRobot2Sum;
}

int main() {

}