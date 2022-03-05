#include<bits/stdc++.h>
#include <vector>

using namespace std;

int h[1005];

bool works(vector<int> n, int num) {
  int loss = 0;
  for(int i = 0; i < n.size(); ++i) {
    n[i] -= loss;
    if(n[i] < num) return 0;
    loss = n[i] - num;
  }
  return (loss == 0);
}

bool tt(vector<int>& a) {
  int N = a.size();
  if(N & 1) {
    long long odd = 0, even = 0;
    for(int i = 0; i < N; ++i) {
      if(i & 1) odd += a[i];
      else even += a[i];
    }
    long long t = abs(even - odd);
    return works(a, t);
  } else {
    int lo = 0, hi = 1000000000;
    while(lo != hi) {
      int mid = (lo + hi) / 2;
      if(works(a, mid)) lo = mid + 1;
      else hi = mid;
    }
    if(lo == 0) return false;
  }
  return true;
}

long long ans = 0;

void r(int cur, vector<int> c) {
  if(cur == 0) {
    ans += tt(c);
  }
  else {
    for(int i = 0; i <= h[cur-1]; ++i) {
      c.push_back(i);
      r(cur-1, c);
      c.pop_back();
    }
  }
}

int main () {
  int N; cin >> N;
  for(int i = 0; i < N; ++i) cin >> h[i];
  r(N, {});
  cout << ans << '\n';
  
}
