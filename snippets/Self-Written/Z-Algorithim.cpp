#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
string s = "1000 charecters";
int z[N];
int L = 0, R = 0;
// https://codeforces.com/blog/entry/3107
void calculate() {
    for (int i = 1; i < N; i++) {
        if (i > R) {
            L = R = i;
            while (R < N && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                 L = i;
                while (R < N && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
     }   
    
}

