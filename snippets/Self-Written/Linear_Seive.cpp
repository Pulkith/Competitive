#include<bits/stdc++.h>

using namespace std;


template <long long N>
vector<int> Seive() {
    bool is_composite[N];
    vector<int> primes;
    for(int i = 2; i < N; ++i) {
        if(!is_composite[i])
            primes.push_back(i);
        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            is_composite[i * primes[j]] = 1;
            if(i%primes[j] == 0) break;
        }
    }
    return primes;
}

int main() {

    auto prime = Seive<100000>();

    for(auto& e : prime)
        cout << e << '\n';
}