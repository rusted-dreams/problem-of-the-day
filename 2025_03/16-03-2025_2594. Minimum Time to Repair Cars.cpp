// problem - 2594. Minimum Time to Repair Cars
// link - https://leetcode.com/problems/minimum-time-to-repair-cars/?envType=daily-question&envId=2025-03-16

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& ranks, long long time, int cars) {
        int count = 0;
        for(int i=0; i<ranks.size(); i++) {
            int num = sqrt(time/ranks[i]);
            count += num;
            if(count >= cars) return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long start = 1;
        long long end = 1ll*ranks[0]*cars*cars;
        long long mid;
        while(start <= end) {
            mid = start + (end-start)/2;
            if(check(ranks, mid, cars)) end = mid-1;
            else start = mid+1;
        }
        return start;

    }
};


// rajan ka most readable code:
// class Solution {
// public:
//     long long repairCars(vector<int>& ranks, int cars) {
//         long long left = 1, right = 1LL * ranks[0] * cars * cars;
//         while (left <= right) {
//             long long mid = left + (right - left) / 2, total = 0;
//             for (auto it : ranks) total += (long long)sqrt(mid / it);
//             if (total >= cars) right = mid - 1;
//             else left = mid + 1;
//         }
//         return left;
//     }
// };

int main() {
    Solution sol;
    
}