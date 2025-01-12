//link - https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/?envType=daily-question&envId=2025-01-12
// problem - 2116. Check if a Parentheses String Can Be Valid

#include <bits/stdc++.h>
using namespace std;

// bool canBeValid(string s, string locked) {
//     if (s.length() % 2 != 0) return false;
//     stack<int> locked_st;
//     stack<int> free_st;
//     for (int i = 0; i < s.length(); i++) {
//         cout << s[i] << " : " << locked[i] << endl;
//         if (locked[i] == '0') free_st.push(i);
//         else if (s[i] == '(') locked_st.push(i);
//         else if (s[i] == ')') {
//             if (!locked_st.empty()) locked_st.pop();
//             else if (!free_st.empty()) free_st.pop();
//             else return false;
//         }
//     }
//     if (locked_st.empty()) return true;
//     else {
//         while (!locked_st.empty()) {
//             if (free_st.empty()) return false;
//             else if (locked_st.top() > free_st.top()) return false;
//             else {
//                 locked_st.pop();
//                 free_st.pop();
//             }
//         }
//     }
//     return true;
// }

// optimised code with O(1) space (without stack)
bool canBeValid(string s, string locked) {
    if (s.length() % 2 != 0) return false;
    int open = 0;
    for (int i = 0; i < s.length(); i++) {
        if (locked[i] == '0') open++;
        else if (s[i] == '(') open++;
        else if (s[i] == ')') open--;
        if (open < 0) return false;
    }

    int close = 0;
    for (int i = locked.length() - 1; i >= 0; i--) {
        if (locked[i] == '0') close++;
        else if (s[i] == ')') close++;
        else if (s[i] == '(') close--;
        if (close < 0) return false;
    }
    return true;
}
int main() {

}