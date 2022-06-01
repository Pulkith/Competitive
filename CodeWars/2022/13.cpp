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

  std::vector<int> split(const std::string &s, char delim) {
    std::vector<int> elems;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delim)) {
        elems.push_back(std::stoi(number));
    }
    return elems;
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  swap(N, M);
  vt<vt<char>> grid(N, vector<char>(M, '#'));
  string s;
  int row= 0;
  while(cin >> s) {   
    if(s == "END") break;
    if(s.back() == ':') {
      s.pop_back();
      row = stoi(s); 
    } else {
      if(s.find('-') != string::npos) {
        auto bo = split(s, '-');
        int lo = bo[0];
        int hi = bo[1];
        FOR(i, lo, hi+1)
          grid[row][i] = ' ';
      } else {
        int c = stoi(s);
        grid[row][c] = ' ';
      }
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j)
        cout << grid[i][j];
    cout << '\n';
  }
  

  return 0;
}
