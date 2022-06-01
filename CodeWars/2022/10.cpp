/**
 * author: DespicableMonkey
 * created: 3/4/2022
 **/ 

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void put(T output) { cout << output << '\n'; }
#define putr(__output) return void(put(__output))

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  int cur = 0;
  bool ok = true;
  int left = 0, right = 0, tot = 0;
  int lopen = 0;
  for(char c : s) {
    cur += (c == '(' ? 1 : -1);
    ok &= (cur >= 0);
    if(c == '(') ++left, ++lopen;
    else ++right;
    if(c == ')' && lopen) {
      --lopen;
      ++tot;
    }
  }
  ok &= (cur == 0);
  cout << "Total left: " << left << '\n';
  cout << "Total right: " << right << '\n';
  cout << "Total pairs: " << tot << '\n';
  cout << (ok ? "Balanced" : "Unbalanced") << '\n';
  return 0;
}
