// link - https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/
// Divide intervals into min. no. of groups

#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>> &intervals){
    // step 1: sort the arr based on starting interval:
    sort(begin(intervals), end(intervals));

    // step 2: store the ending of the group in min-heap:
    priority_queue<int, vector<int>, greater<int>> pq;

    // step 3: process each interval one by one:
    for (vector<int> &interval : intervals)    {
        int start = interval[0];
        int end = interval[1];
        if (!pq.empty() && start > pq.top()){
            pq.pop();
        }
        pq.push(end);
    }
    // step 4: return the size of pq as ans:
    return pq.size();
}
int main(){
}