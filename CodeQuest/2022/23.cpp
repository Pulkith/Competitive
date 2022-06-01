#include<bits/stdc++.h>
#include <bitset>
#include <ratio>
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


std::string int_to_hex( long i )
{
  std::stringstream stream;
  stream << "0x" 
         << std::setfill ('0') << std::setw(sizeof(long)*2) 
         << std::hex << i;
  return stream.str();
}
void test_case() {
        string w; getline(cin, w);
        string res = "";
        for(char c : w) {
          bitset<7> bin_x(c - 'A');
          string kk = bin_x.to_string();
          res += kk;
        }
        while(res.length() % 128 != 0) res += "1";

        unsigned int A = 792250721;
        unsigned int B = 683117105 ; 
        unsigned int C = 1215387974;
        unsigned int  D = 1767829900;
        for(int i = 0; i < 128 / 32; ++i) {
          string chunk = res.substr(0 + 32 * i, 32);
          unsigned int S = (B ^ D) & (C | (~B));
          S = A + S;
          S = S + stoll(chunk, nullptr, 2);
          for(int j = 0; j < (i % 32); ++j) {
            long top = S & (1 << (31));
            S = S << 1;
            S += top;
          }
          A = D;
          D = C;
          C = B;
          B = S;
        }
        bitset<32> a(A), b(B), c(C), d(D);
        string re = ts(A) + ts(B) + ts(C) + ts(D);
        string fin = "";
        for(int i = 0; i < re.length() / 4; ++i) {
          string ss = re.substr(i * 4, 4);
          int num = stoll(ss, nullptr, 2);
          fin += int_to_hex(num);
        }
        cout << fin << '\n';

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
