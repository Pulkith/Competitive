/**
 * author: DespicableMonkey
 * created: 01.29.2022 12:26:48
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
    template<class T> void outv(vector<T>& v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
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

bool works(vt<int> n, int num) {
  int loss = 0;
  FOR(i, 0, sz(n)) {
    n[i] -= loss;
    if(n[i] < num) return false;
    loss = n[i] - num;
  }
  return (loss == 0);
}


void test_case() {
    vt<int> n(7);
    FOR(a, 1, 11)
      FOR(b, 1, 11)
        FOR(c, 1, 11)
          FOR(d, 1, 11)
            FOR(e, 1, 11)
              FOR(f, 1, 11)
                FOR(g, 1, 11) {
                  n[0] = a;
                  n[1] = b;
                  n[2] = c;
                  n[3] = d;
                  n[4] = e;
                  n[5] = f;
                  n[6] = g;

                  int l = *min_element(all(n));

                  int odd = 0, even = 0;
                  for(int i = 0; i < sz(n); ++i){
                    if(i & 1) odd += n[i];
                    else even += n[i];
                  }

                  bool ok = 0;
                  int res = 0;

                  for(int z = l; z >= 0; --z) {
                    if(works(n, z)) {
                      ok = 1;
                      res = z;
                      // if(abs(even - odd) != z) cout << "NO" << '\n';
                      // if(z != l) put("NO");
                      // cout << even - odd << '\n';
                      break;
                    }
                  }


                  if(ok){

                    // int odd1 = 0, even1 = 0;
                    // for(int i = 0; i < sz(n); ++i){
                    //   if(i & 1 && i > 1) odd1 += n[i] - n[i-2];
                    //   if(i % 2 == 0 && i > 0) even1 += n[i] - n[i-2];
                    // }
                    // if(abs(odd1 - even1) != res) cout << "NO" << '\n';

                    // cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << " " << n[4] << " " << n[5] << "(" << odd << ")" <<" -> " << res << '\n';
                  }
                  if(ok) {
                    // && (even - odd > 0) && (even - odd < l)
                     cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << " " << n[4] << " " << n[5] << " " << n[6] << " (" << odd <<  " " << even << ") " << '\n';
                  }
                  // if(!ok && (even == odd))
                    // cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << " " << n[4] << " " << n[5] << "(" << odd << ")" << '\n';

                }

}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);
  CP::IO().setOut("ans.txt");
  my_brain_hurts
  // cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
