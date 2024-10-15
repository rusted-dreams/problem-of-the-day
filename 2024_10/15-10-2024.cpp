// 2938. Separate Black and White Balls
// link - https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

#include<iostream>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long blacks = 0; // count the no. of black balls in left before a 0.
        for(long long i=0; i<s.length(); i++){
            if(s[i] == '1'){
                blacks += 1; //count the no. of black balls in left before a 0.
            }
            else{
                ans += blacks;
            }
        }
        return ans;
    }
};