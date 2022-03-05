/*
  Author: DespicableMonkey
*/
 
#include <bits/stdc++.h>
using namespace std;
int N, K, runningsum = 0, doublesum = 0;
long double vals[(int)1e4 + 25];
double cdf[(int)1e4+25], E_cdf[(int)1e4+25];
long double b = 0, p = 0.5;
int main(){
  cout << fixed << showpoint << setprecision(10);
  cin >> N >> K;
  for(int k = 0; k < N; ++k) {
    long double t = k;
    if(k > 0) b += log(N-t) - log(t);
    long double lb = b + t * log(p) + (N-1-t) * log(1-p);
    vals[k+1] = exp(lb);
  }
  for(int i = 1; i <= N; ++i) {
    cdf[i] = cdf[i-1] + vals[i];
    E_cdf[i] = vals[i] * i + E_cdf[i-1];
  }
  double state = E_cdf[N], top = 0;
  for(int i = 1; i <= N; ++i)  E_cdf[i] = state - E_cdf[i];
  int tresh = N >> 1, skip = 0;
  for(int lvl = 2; lvl <= K; ++lvl, top = 0, ++runningsum, skip = 0) {
    top = cdf[tresh - 1] * state + E_cdf[tresh - 1];
    double add = cdf[tresh] * state + E_cdf[tresh];
    while(tresh < N && top < add)  {
      ++tresh; ++skip;
      top = add;
      add = cdf[tresh] * state + E_cdf[tresh];
    }
    state = top;
    if(skip) {
        lvl += runningsum = doublesum = min(runningsum-1, K - lvl);
        double p = pow(cdf[tresh-1], doublesum);
        state = p * state + E_cdf[tresh - 1] * (p - 1) / (cdf[tresh-1] - 1);
      }
  }
 
  cout << state << '\n';
}
 

