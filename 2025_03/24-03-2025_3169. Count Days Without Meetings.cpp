// problem - 3169. Count Days Without Meetings
// link - https://leetcode.com/problems/count-days-without-meetings/?envType=daily-question&envId=2025-03-24

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int res = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < meetings.size(); i++) {
            start = meetings[i][0];
            if (start > end) res += start - end - 1;
            end = max(end, meetings[i][1]);
        }
        if (days > end) res += days - end;
        return res;
    }
};


// using diff array - memory limit exceeded
// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         vector<int> diff(days+1, 0);
//         for(auto& it : meetings) {
//             diff[it[0]-1] += 1;
//             diff[it[1]]  -= 1;
//         }
//         int count = 0;
//         for(int i = 1; i<days; i++) {
//             diff[i] = diff[i] + diff[i-1];
//             if(diff[i] > 0) count++;
//         }
//         if(diff[0] > 0) count++;
//         return days - count;   
//     }
// };

// using set - TLE:
// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         unordered_set<int> st;
//         for(auto& it : meetings){
//             for(int i = it[0]; i <= it[1]; i++){
//                 st.insert(i);
//             }
//         }
//         return days - st.size();
//     }
// };

int main() {
    Solution sol;

}