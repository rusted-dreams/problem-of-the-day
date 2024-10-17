// 670. Maximum Swap
// link - https://leetcode.com/problems/maximum-swap/?envType=daily-question&envId=2024-10-17

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num); //convert num to string
        string s = n;

        //sort the digits in descending order        
        sort(s.rbegin(), s.rend());
        int firstPos = 0;
        char secondDigit = n[0];

        // comparing the original and sorted string.
        // we need to swap the digits when there is a mismatch of digits.
        for(int i=0; i<n.length(); i++){
            if(n[i] != s[i]){
                firstPos = i; // note the pos. of the first digit to be swapped with.
                secondDigit = s[i]; // note the digit swapped with
                break;
            }
        }

        // find the second in n from back of the string and swap with first digit.
        for(int i = n.length()-1; i>firstPos; i--){
            if(n[i] == secondDigit){
                swap(n[firstPos], n[i]);
                break;
            }
        }
        return stoi(n);
    }
};


int main() {
    
}