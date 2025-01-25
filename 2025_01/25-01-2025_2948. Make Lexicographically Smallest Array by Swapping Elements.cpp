// problem - 2948. Make Lexicographically Smallest Array by Swapping Elements
// link - https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2025-01-25

#include <bits/stdc++.h>
using namespace std;

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    // Step 1: Create a copy of the input array and sort it to process elements in sorted order
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    // Step 2: Data structures to manage groups and their assignments
    // groups: maps each group index to the list of elements in that group
    // elementGroup: maps each element to its group index for quick lookup
    unordered_map<int, list<int>> groups;
    unordered_map<int, int> elementGroup;
    int groupCount = 0; // Initialize group counter

    // Step 3: Assign the first element to the initial group
    elementGroup[sorted[0]] = groupCount;
    groups[groupCount].push_back(sorted[0]);

    // Step 4: Group the elements based on the 'limit' constraint
    for (int i = 1; i < nums.size(); i++) {
        // If the difference between the current and previous sorted elements exceeds the limit,
        // create a new group for the current element
        if (sorted[i] - sorted[i - 1] > limit) {
            groupCount++;
        }
        // Assign the current element to the appropriate group
        elementGroup[sorted[i]] = groupCount;
        groups[groupCount].push_back(sorted[i]);
    }

    // Step 5: Build the resulting array by replacing each element with the smallest available
    // element from its assigned group (to maintain lexicographical order)
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int group = elementGroup[nums[i]]; // Find the group of the current element
        res[i] = *groups[group].begin();  // Pick the smallest element from the group
        groups[group].pop_front();       // Remove the used element from the group
    }

    // Step 6: Return the resulting lexicographically smallest array
    return res;
}

int main() {

}