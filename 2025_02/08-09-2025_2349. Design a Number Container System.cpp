// problem - 2349. Design a Number Container System
// link - https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08

#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    // Maps index to number stored at that index
    unordered_map<int, int> idxToNum;
    
    // Maps number to set of indices where it appears
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {
        
    }
    
    void change(int idx, int num) {
        // If index already exists, update both maps
        if(idxToNum.find(idx) != idxToNum.end()) {
            int oldNum = idxToNum[idx];
            auto &indices = numToIdx[oldNum];
            indices.erase(idx);

            // Remove number entry if no indices left
            if(indices.empty()) numToIdx.erase(oldNum);

            // Update with new number
            idxToNum[idx] = num;
            numToIdx[num].insert(idx);
        }

        // If new index, simply insert into both maps
        else {
            idxToNum[idx] = num;
            numToIdx[num].insert(idx);
        }
    }
    
    int find(int num) {

        // Return smallest index where number appears, or -1 if not found
        if(numToIdx.find(num) == numToIdx.end()) return -1;
        return *numToIdx[num].begin();
    }
};

int main() {
    
}