#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>

using namespace std;

#define ll long long

#define vi vector<int>
#define pb push_back

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;

bitset<10000010> bs; //10^7 + small extra bits
vi primes;
ll _seive_size;

//can go up to 10^7
void SeiveOfE(ll upperbound) {
    _seive_size = ++upperbound;
    bs.reset();
    bs.flip();

    bs.set(0, false);
    bs.set(1, false);

    for(ll i = 2; i <= upperbound; ++i){
        if(bs.test((size_t)i)) {
            for(ll j = i * i; j <= upperbound; j += i) {
                bs.set((size_t)j, false);
                primes.pb((int)i);
            }
        }
    }
}

//Deterministic Prime Tester
bool isPrime(ll N) {
    if(N < _seive_size) return bs.test(N);
    for(int i = 0; i < primes.size(); ++i)
        if(N % primes[i] == 0) 
            return false;
    return true;
    //only works if N <= (last prime in 'primes')^2
}

vi PrimeFactors(int N) {
    vi factors;
    int PF_index = 0;
    int PF = factors[PF_index];
    while(N != 1 && (PF * PF <= N)) {
        while(N % PF == 0) {
            N /= PF;
            factors.pb(PF);
        }
        PF = primes[++PF_index];
    }
    //N is Prime
    if(N != 1) factors.pb(N); 
    return factors;
}

int EulerPhi(int n) {
    //calculate number of numbers from 1...N that are relatively prime to N;

    vi factors = PrimeFactors(n);
    vi::iterator new_end = unique(factors.begin(), factors.end());
    int result = n;
    for(vi::iterator i = factors.begin(); i != new_end; ++i) {
        result = result - result / *i;
    }
    return result;

}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);


}