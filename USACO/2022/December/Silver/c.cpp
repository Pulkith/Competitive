/**
 * author: DespicableMonkey
 * created: 12.20.2021 16:10:53
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;


int N, K;
pair<int, int> pairs[250000];

int main () {
  cin >> N >> K;
  for(int i = 0; i < N; ++i)
    cin >> pairs[i].first >> pairs[i].second;
  sort(pairs, pairs + N);

  vector<long long> prefix1(15000);
  vector<long long> prefix2(15000);

  vector<long long> ans(15000);

  for(int i = 0; i < N; ++i) {
    prefix1[pairs[i].first] += 1;
    prefix2[pairs[i].second] += 1;
  }  

  for(int i = 0; i <= 2 * K; ++i) {
    for(int j = 0; j <= K; ++j) {
      if(j > i) break;
      ans[i] += prefix1[j] * 1LL * prefix1[i - j];
      ans[i+1] -= prefix2[j] * 1LL * prefix2[i - j];
    }
  } 
  partial_sum(ans.begin(), ans.end(), ans.begin());
  for(int i = 0; i <= 2 * K; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}
