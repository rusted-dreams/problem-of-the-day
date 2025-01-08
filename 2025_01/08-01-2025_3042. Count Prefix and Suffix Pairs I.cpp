// link - https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-08
// problem - 3042. Count Prefix and Suffix Pairs I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // bruteforce approach needs optimization
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for(int i=0; i<words.size(); i++){
            bool prefix = true;
            bool suffix = true;
            for(int j=i+1; j<words.size(); j++){
                string str1 = words[i];
                string str2 = words[j];
                if(str1.length() <= str2.length()){
                    for(int k=0; k<str1.length(); k++){
                        if(str1[k] != str2[k]) {
                            prefix = false;
                            break;
                        }
                    }
                    int a = str1.size() - 1;
                    int b = str2.size() - 1;
                    for(a; a>=0; a--){
                        if(str1[a] != str2[b]){
                            suffix = false;
                            break;
                        }
                        b--;
                    }
                    if(prefix && suffix) {
                        res++;
                    }
                    prefix = true;
                    suffix = true;
                }
            }
        }
        return res;
    }
};

int main() {
    
}