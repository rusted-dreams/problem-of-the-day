// problem - 2425. Bitwise XOR of All Pairings
// link - https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include <bits/stdc++.h>
using namespace std;

// if nums1 is odd the ans is xor or nums2 and vice versa. if both are even return 0 and if both are odd return xor of nums1 and nums2.
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0)return 0;
    int xor1 = 0, xor2 = 0;
    for (int i : nums1) xor1 = xor1 ^ i;
    for (int i : nums2) xor2 = xor2 ^ i;

    if (nums1.size() % 2 == 1) return xor2;
    if (nums2.size() % 2 == 1) return xor1;

    else return xor1 ^ xor2;
}
int main() {

}