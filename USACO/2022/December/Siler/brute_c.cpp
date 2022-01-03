#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>

using namespace std;
#define sz(x) (int)(x).size()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)
#define ll long long

inline namespace CP {
  class IO { public:
    void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
    void Input(int __use_input = 0) {if(!!__use_input){setIn(to_string(__use_input)+".in");}}
    IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
    IO* SetIO(string __s = "", string __t = "") {
      cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
      if(sz(__t)) setIn(__s), setOut(__t);
      else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
      return this;
    }
  };
}

int N, K;
pair<int, int> a[200005];
ll ans_a[10005];
ll ans_b[10005];

int nums[10005], nums2[10005];

int main () {
  cin.tie(0)->sync_with_stdio(0);
  CP::IO().Input(1);
  cin >> N >> K;
  FOR(i, 0, N) cin >> a[i].first >> a[i].second;
  sort(a, a+N);
  
  FORE(i, 0, 2 * K) {
    int cur = 0;
    FOR(j, 0, N) {
      FOR(k, 0, N) {
        if(a[j].first + a[k].first <= i && i <= a[j].second + a[k].second)
          ++cur;
      }
    }
    cout << "["<< i << "]: " << cur << '\n';
  }

  return 0;
}
