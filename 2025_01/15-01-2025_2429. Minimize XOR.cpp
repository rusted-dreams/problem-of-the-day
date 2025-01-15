// problem - 2429. Minimize XOR
// link - https://leetcode.com/problems/minimize-xor/?envType=daily-question&envId=2025-01-15

#include <bits/stdc++.h>
using namespace std;

int minimizeXor(int num1, int num2) {
    int setBits = 0;
    int a = num2;
    int x = 0;
    while (a) {
        if (a & 1) setBits++;
        a = a >> 1;
    }
    for (int i = 31; i >= 0 && setBits; i--) {
        if (num1 & (1 << i)) {
            x = x | (1 << i);
            setBits--;
        }
    }
    for (int i = 0; i <= 31 && setBits; i++) {
        if (!(num1 & (1 << i))) {
            x = x | (1 << i);
            setBits--;
        }
    }
    return x;
}
int main() {

}