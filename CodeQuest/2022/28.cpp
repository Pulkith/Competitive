#include<bits/stdc++.h>
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
int N;
int a[MX];


void test_case() {
    

}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);

  int Test_Cases = 0;
  cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt)
      test_case();
  return 0;
}
