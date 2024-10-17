// 1405 - Longest Happy String
// link - https://leetcode.com/problems/longest-happy-string/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    typedef pair<int, char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p, vector<p>> pq; 
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(result.length()>=2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar){
                if(pq.empty()) break;
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                
                nextCount--;
                result.push_back(nextChar);
                if(nextCount > 0) pq.push({nextCount, nextChar});
            } else{
                result.push_back(currChar);
                currCount--;
            }
            if(currCount > 0) pq.push({currCount, currChar});
        }
        return result;

    }
};