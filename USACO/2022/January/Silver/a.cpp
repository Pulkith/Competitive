#include<bits/stdc++.h>

using namespace std;


long long low(long long a, long long b) {
  long long doublings = 0;
  long long c = a;
  while(c * 2 <= b) {
    ++doublings;
     c*=2;
  }
  long long need = b - c;

  vector<long long> opts;
  c = a;
  while(c <= b) {
    opts.push_back(c);
    c *= 2;
  }

  c = a;
  map<long long, long long> subtracted;
  long long down = 0;
  while(c > 1) {
    if(c & 1) subtracted[doublings + down + 1] += pow(2, doublings + down);
    c = (c+1) / 2;
    opts.push_back(c);
    ++down;
    subtracted[down + doublings + 1] += subtracted[down + doublings];
  }
  sort(opts.begin(), opts.end());
  long long ans = abs(b - a);
  for(auto start : opts) {
    long long level = down + doublings;
    long long needx = need - subtracted[level];
    if(needx >= 0){
      long long ops = __builtin_popcount(subtracted[level]) + abs(down);
      c = start;
      while(level) {
        long long num = pow(2, level);
        if(num <= needx) {
          long long opsadd = needx / num;
          ops += opsadd;
          needx -= opsadd * num;
          c += opsadd;
        }
        ++ops; --level; c *=2;
      }
      ops += abs(c - b);
      ans = min(ans, ops);
    }
    --down;
  }

  return ans;
}

long long high(long long a, long long b) {
  long long ops = 0;
  while(a > b) {
    if(a&1) ++a;
    else a /= 2;
    ++ops;
  }

  if(a == b) return ops;
  return ops + low(a, b);
}

int main () {
  int T = 1; 
  cin >> T;
  while(T -- ) {
      long long a, b, ans = 0;
      cin >> a >> b;
      if(a < b) ans = low(a, b);
      else if(a > b) ans = high(a, b);
      cout << ans << '\n';
  }
}
