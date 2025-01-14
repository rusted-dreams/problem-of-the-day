// problem - 2657. Find the Prefix Common Array of Two Arrays
// link - https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2025-01-14

#include <bits/stdc++.h>
using namespace std;

// vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//     vector<int> ans;
//     int res = 0;
//     unordered_set<int> mp1;
//     unordered_set<int> mp2;

//     for (int i = 0; i < A.size(); i++) {
//         mp1.insert(A[i]);
//         mp2.insert(B[i]);
//         if (A[i] == B[i]) {
//             res++;
//             ans.push_back(res);
//             continue;
//         }
//         if (mp1.find(B[i]) != mp1.end()) {
//             res++;
//             mp1.erase(B[i]);
//         }
//         if (mp2.find(A[i]) != mp2.end()) {
//             res++;
//             mp2.erase(A[i]);
//         }
//         ans.push_back(res);
//     }
//     return ans;
// }


// another approach:
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> ans;
    int res = 0;
    vector<int> freq(A.size() + 1, 0);
    for (int i = 0; i < A.size(); i++) {
        freq[A[i]]++;
        if (freq[A[i]] == 2) res++;

        freq[B[i]]++;
        if (freq[B[i]] == 2) res++;

        ans.push_back(res);
    }
    return ans;
}
int main() {

}