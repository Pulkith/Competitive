#include<bits/stdc++.h>
#include <queue>
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

const int MX = (2e5+43);
int a[MX];

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
    int N, M;
    string s; getline(cin, s);
    auto v = split(s, ',');
    N  = stoi(v[0]), M = stoi(v[1]);
    map<string, int> len;
    map<int, vector<pr<pr<int, int>, string>>> m;
    FOR(i, 0, M) {
      getline(cin, s);
      auto vv = split(s, ',');
      m[stoi(vv[2])].pb({{stoi(vv[1]), i}, vv[0]});
      len[vv[0]] = stoi(vv[3]);
    }
    auto cmp = [](auto a, auto b) { 
      if(a.f.f == b.f.f) return a.f.s > b.f.s;
      return a.f.f < b.f.f;
    };


    priority_queue<pr<pr<int, int>,string>, vector<pr<pr<int, int>,string>>, decltype(cmp)> pq(cmp);

    string cur = "";
    FORE(i, 1, N) {
      for(auto k : m[i]) pq.push(k);
      if(sz(pq)) {
        auto vvv = pq.top(); pq.pop();
        len[vvv.s] -= 1;
        if(len[vvv.s] > 0) pq.push(vvv);
        cur = vvv.s;
      }
      else cur = "Wait";
      cout << ts(i) << "," << cur << '\n';
    }

}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);

  int Test_Cases = 0;
  string s; getline(cin, s);
  Test_Cases = stoi(s);

  for(int tt = 1; tt <= Test_Cases; ++tt)
      test_case();
  return 0;
}
