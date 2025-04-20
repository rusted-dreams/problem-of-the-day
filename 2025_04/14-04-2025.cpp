// problem - 
// link - 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x = arr[i];
                    int y = arr[j];
                    int z = arr[k];
                    if ((abs(x - y) <= a) && (abs(y - z) <= b) && (abs(x - z) <= c)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

}