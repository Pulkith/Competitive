#include<bits/stdc++.h>
#include <string>
#include <unordered_map>
#if LOCAL
  #include <DespicableMonkey/Debug.h>
#endif
#if !defined LOCAL
  #define dbg(...) ;
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)
#define has(container, element) ((bool)(container.find(element) != container.end()))

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> void put(T output) { cout << output << '\n'; }
#define putr(__output) return void(put(__output))


int cc(pair<int, int> p1, pair<int, int> p2, pair<int, int> p){
  int dy = p2.f - p1.f;      
  int dx = p2.s - p1.s;

  


}
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
void test_case() {
    int N, M, K;
    string s; 
    getline(cin, s);
    auto kk = split(s, ' ');
    N = stoi(kk[0]); M = stoi(kk[1]); K = stoi(kk[2]);
    vector<vector<char>> g(N, vector<char>(M, ' '));
    FOR(i, 0, N) {
      getline(cin, s);
      FOR(j, 0, sz(s)) {
        g[i][j] = s[j];
      }
    }
    map<int, pr<int, int>> point;
    FOR(i, 0, N) {
      FOR(j, 0, M) {
        if(g[i][j] >= '0' && g[i][j] <= '9')
          point[g[i][j] - '0'] = {i, j};
      }
    }
    vt<int> v;
    FORE(i, 1, 9) {
      if(has(point, i)) {
        bool go = true;
        FOR(ii, 0, N) {
          FOR(jj, 0, M) {
            pr<int, int> vv = {ii, jj};

            if(i == 2) {
              cout << ii << " " << jj << " " << cc(point[0], point[i], {ii, jj}) << '\n';
            }

            if(point[0] != vv && point[i] != vv && cc(point[0], point[i], {ii, jj})) {
                go &= (g[ii][jj] == ' ');
            }
          }
        }
        if(go)
          v.pb(i);
      }
    }
    if(sz(v)) {
      string ans = "";
      for(auto i : v) ans += ts(i) + " ";
        ans.pop_back();
      cout <<  ans << '\n';
    }
    else cout << "No viable locations" << '\n';


}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);

  int Test_Cases = 0;
  // cin >> Test_Cases;
  string s;
  getline(cin, s);
  Test_Cases = stoi(s);

  for(int tt = 1; tt <= Test_Cases; ++tt)
      test_case();
  return 0;
}
