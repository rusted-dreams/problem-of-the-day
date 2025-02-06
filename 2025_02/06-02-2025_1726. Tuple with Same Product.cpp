// problem - 1726. Tuple with Same Product
// link - https://leetcode.com/problems/tuple-with-same-product/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Use an unordered_map `freq` to store the frequency of each unique product formed by pairs of numbers.
2. Iterate over all pairs (i, j) and compute `nums[i] * nums[j]`.
3. If the product has been seen before, it means additional valid tuples can be formed.
4. Increment `count` based on previous occurrences of the product.
5. Since each valid tuple contributes 8 permutations, multiply the final count by 8.
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> freq; // Stores frequency of each product
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                
                // If product has been seen before, it forms additional valid tuples
                if (++freq[product] >= 2) 
                    count += freq[product] - 1;
            }
        }
        
        return count * 8; // Each valid tuple contributes 8 permutations
    }
};


int main() {
    Solution sol;
    
}