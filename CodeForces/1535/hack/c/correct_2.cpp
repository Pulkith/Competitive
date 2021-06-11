#include <bits/stdc++.h>
using namespace std;

namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() {
            cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
        }
        void setIO(string s = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if (s.size()) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
        void setIO(string s, string t) {
            setIn(s);
            setOut(t);
        }
    }
    inline namespace ExecTime {
        #define cur_t std::chrono::high_resolution_clock::now() /* 64 mil =  ~1 second */
        auto _start_time = cur_t;
        bool use = 0;
        void use_clock() { use = 1; }
        void log_time(bool start = true) {
            if(use) {
                if(!start) {
                    auto _stop_time = cur_t;
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(_stop_time - _start_time);
                    cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n';
                }
                else
                    _start_time = cur_t;
            }
        }
    }
}
int main(){
    CP::IO::setIn("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/c/inc1.input");
    CP::IO::setOut("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/c/output_2.txt");
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> a(3);
    for (int j = 0; j < 3; j++){
      a[j].push_back(-1);
    }
    for (int j = 0; j < N; j++){
      if (s[j] != '?'){
        a[2].push_back(j);
        int d = s[j] - '0';
        int p = (d + j) % 2;
        a[p].push_back(j);
      }
    }
    for (int j = 0; j < 3; j++){
      a[j].push_back(N);
    }
    vector<long long> S(3, 0);
    for (int j = 0; j < 3; j++){
      int cnt = a[j].size();
      for (int k = 0; k < cnt - 1; k++){
        long long d = a[j][k + 1] - a[j][k];
        S[j] += d * (d - 1) / 2;
      }
    }
    cout << S[0] + S[1] - S[2] << endl;
    fflush(stdout);
  }
}