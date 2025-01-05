// link - https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
// problem: 2381. Shifting Letters II

#include <bits/stdc++.h>
using namespace std;

// solved using difference array approach 
// approach almost mera khud ka tha but pata nhi tha implementation ke liye difference array lagega so wo dekhna pada tha
string shiftingLetters(string s, vector<vector<int>>& shifts) {
    //initialize a array to store the final amount of shifts to perform:
    vector<int> finalShift(s.length(), 0);
    for (auto& i : shifts) {
        int start = i[0];
        int end = i[1] + 1;
        int x = i[2] > 0 ? 1 : -1;

        finalShift[start] += x;
        if (end < finalShift.size())
            finalShift[end] -= x;
    }
    // take the cummulative sum of the difference arr to arrive at the final amounts of shifts of each char
    for (int i = 1; i < finalShift.size(); i++) {
        finalShift[i] = finalShift[i - 1] + finalShift[i];
    }
    // handle over and underflow and make the final updates to the string:
    for (int i = 0; i < s.length(); i++) {
        int letter = s[i] - 'a';
        letter += finalShift[i];
        letter = letter % 26;
        if (letter < 0) {
            letter += 26;
        }
        s[i] = 'a' + letter;
    }
    return s;
}
int main() {

}