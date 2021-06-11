#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = (int)(1e9 + 7);

ll exp(ll x, ll n){
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)
        return exp((x * x) % MOD, n / 2);
    if (n % 2 == 1)
        return (x * exp((x * x) % MOD, n / 2)) % MOD;
}