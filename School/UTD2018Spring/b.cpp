/**
 * author: DespicableMonkey
 * created: 10.22.2021 19:18:10
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

int main () {
    int T; cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        long long ans = 0;
        for(int i = 1; i <= K; ++i) {
            ans += i+1;
        }
        cout << N << " " << ans << '\n';
    }
}
