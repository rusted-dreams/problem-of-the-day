#include <bits/stdc++.h>
using namespace std;

bool canBeValid(string s, string locked) {
    stack<int> locked_st;
    stack<int> free_st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') !locked[i] ? free_st.push(i) : locked_st.push(i);
        else if (s[i] == ')' && !locked[i]) free_st.push(i);
        else {
            if (locked_st.empty() && free_st.empty()) return false;
            cout << "here " << endl;
            if (!locked_st.empty()) locked_st.pop();
            else free_st.pop();
        }
    }
    cout << "here" << endl;
    while (!locked_st.empty()) {
        if (locked_st.top() > free_st.top()) return false;
        locked_st.pop();
        free_st.pop();
    }
    cout << free_st.size() << endl;
    if (free_st.size() % 2 == 0) return true;
    else return false;
}
int main() {
    canBeValid("))()))", "010100");
}