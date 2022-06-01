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


bool isChar(char c) {
  return (c >= 'A' && c <= 'Z');
}

void test_case() {
    cout << setprecision(3) << fixed;
    string kk; getline(cin, kk);
    int M = stoi(kk);
    vector<string> words;
    FOR(k, 0, M) {
      string s; getline(cin, s);
      transform(s.begin(), s.end(), s.begin(), ::toupper); 
      string ss = "";
      for(char c : s) {
        if(isChar(c) || c == ' ') ss += c;
      }
      s = ss;
      for(int i = 0; i < sz(s); ++i) {
        if(i == 0 || (!isChar(s[i-1]) && isChar(s[i]))) {
          words.pb("");
          words.back() += s[i];
        } else if(isChar(s[i])) {
          words.back() += s[i];
        }
      }
    }
    map<string, double> f, f2;
    int count = 0, count2 = 0;
    for(auto w : words) {
      for(int i = 0; i < sz(w) -1; ++i) {
        ++count;
        string k = string(1, w[i]) + string(1, w[i+1]);
        f[k]++;
      }
      for(int i = 0; i < sz(w) - 2; ++i) {
        ++count2;
        string k = string(1, w[i]) + string(1, w[i+1]) + string(1, w[i+2]);
        f2[k]++;
      }
    }

    for(auto [x,y] : f) {
      cout << x <<": " << (y / count * 100 ) << "%" << '\n';
    }

    for(auto [x,y] : f2) {
      cout << x <<": " << (y / count2 * 100 ) << "%" << '\n';
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
