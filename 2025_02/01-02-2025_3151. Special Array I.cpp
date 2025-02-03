// problem - 3151. Special Array I
// link - https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        if(arr.size() == 1) return true;
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i]%2 == arr[i+1]%2) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> a = {5, 6, 7, 8};
    bool ans = sol.isArraySpecial(a);
    // cout << ans << endl;
}