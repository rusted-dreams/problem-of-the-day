//link - https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/?envType=daily-question&envId=2025-01-06
// problem - 1769. Minimum Number of Operations to Move All Balls to Each Box.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> minOperations(string boxes) {
    //     vector<int> idx;
    //     vector<int> ans(boxes.length());
    //     for(int i=0; i<boxes.length(); i++){
    //         if(boxes[i] == '1') {
    //             idx.push_back(i);
    //         }
    //     }
    //     for(int i=0; i<boxes.length(); i++){
    //         int moves = 0;
    //         for(int j:idx){
    //             moves += abs(i-j);
    //         }
    //         ans[i] = moves;
    //     }
    //     return ans;

    // }
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        int cumValue = 0;
        int cumSum = 0;

        // for left balls:
        for(int i=0; i<boxes.length(); i++){
            ans[i] = cumSum;
            if(boxes[i] == '1'){
                cumValue++;
            }
            cumSum += cumValue;
        }
        cumValue =0;
        cumSum =0;
        // for right balls:
        for(int i=boxes.length()-1; i>=0; i--){
            ans[i] += cumSum;
            if(boxes[i] == '1'){
                cumValue++;
            }
            cumSum += cumValue;
        }
        return ans;
       

    }
};


int main() {
    
}