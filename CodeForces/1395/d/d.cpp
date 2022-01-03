/**
 * author: DespicableMonkey
 * created: 12.13.2021 23:25:37
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
  #include <DespicableMonkey/Execution_Time.h>
  #include <DespicableMonkey/Debug.h>
  #define debug_active 1
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int Test_Cases = 1;

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

inline namespace CP {
  inline namespace Output {
    #if !defined LOCAL
      #define dbg(...) ;
      #define print_test_case(...) ;
      #define debug_active 0
    #endif
    template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
    template<class T> void put(T output) { cout << output << '\n'; }
    #define putr(__output) return void(put(__output))
  }
  class IO { public:
    void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
    void Input(int __use_input = 0) {if(!!__use_input && debug_active){setIn("in"+to_string(__use_input)+".txt");}}
    IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
    IO* SetIO(string __s = "", string __t = "") {
      cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
      if(sz(__t) && !debug_active) setIn(__s), setOut(__t);
      else if (sz(__s) && !debug_active) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
      return this;
    }
  };
}

const int MX = (2e5+43);
int N, D, M;
int a[MX];


void test_case() {
  cin >> N >> D >> M;
  FOR(i, 0, N) cin >> a[i];
  vt<int> muzzles, singles;
  FOR(i, 0, N) {
    if(a[i] > M) muzzles.pb(a[i]);
    else singles.pb(a[i]);
  }    
  sort(all(muzzles)); reverse(all(muzzles));
  sort(all(singles)); reverse(all(singles));

  vt<ll> mAccum, sAccum;
  FOR(i, 0, sz(muzzles)) {
    if(!sz(mAccum)) mAccum.pb(muzzles[i]);
    else mAccum.pb(muzzles[i] + mAccum.back());
  }
  FOR(i, 0, sz(singles)) {
    if(i == 0) sAccum.pb(singles[i]);
    else sAccum.pb(singles[i] + sAccum.back());
  }

  ll ans = 0;

  // dbg(sz(mAccum), sz(sAccum));

  FORE(seg_takes, 0, sz(mAccum)) {
    ll res = (seg_takes > 0 ? mAccum[seg_takes - 1] : 0);
    int daysmuzzled = seg_takes + (max(seg_takes - 1, 0)) * D;
    // dbg(seg_takes, daysmuzzled);
    if(daysmuzzled > N) break;
    int singledays_used = daysmuzzled - seg_takes - (sz(muzzles) - seg_takes); cmax(singledays_used, 0);
    int remdays_can_use = sz(singles) - singledays_used;
    // dbg(singledays_used, remdays_can_use);
    assert(remdays_can_use >= 0);
    res += (remdays_can_use > 0 ? sAccum[remdays_can_use - 1] : 0);
    cmax(ans, res);
  }

  put(ans);

}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
