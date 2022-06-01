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
string word[200] = {
"####",
"#  #",
"####",
"#  #",
"#  #",

"####",
"#  #",
"####",
"#  #",
"####",

"####",
"#   ",
"#   ",
"#   ",
"####",

"### ",
"#  #",
"#  #",
"#  #",
"### ",

"####",
"#   ",
"### ",
"#   ",
"####",

"####",
"#   ",
"####",
"#   ",
"#   ",

"####",
"#   ",
"# ##",
"#  #",
"####",

"#  #",
"#  #",
"####",
"#  #",
"#  #",

"####",
" #  ",
" #  ",
" #  ",
"####",

"####",
"  # ",
"  # ",
"# # ",
"### ",

"#  #",
"# # ",
"##  ",
"# # ",
"#  #",

"#   ",
"#   ",
"#   ",
"#   ",
"####",

"#   #",
"## ##",
"# # #",
"#   #",
"#   #",

"#   #",
"##  #",
"# # #",
"#  ##",
"#   #",

"####",
"#  #",
"#  #",
"#  #",
"####",

"####",
"#  #",
"####",
"#   ",
"#   ",

"#### ",
"#  # ",
"#  # ",
"# ## ",
"### #",

"#### ",
"#  # ",
"#### ",
"# #  ",
"#   #",

"####",
"#   ",
"####",
"   #",
"####",

"####",
" #  ",
" #  ",
" #  ",
" #  ",

"#  #",
"#  #",
"#  #",
"#  #",
"####",

"#   #",
"#   #",
" # # ",
" # # ",
"  #  ",

"#   #",
"#   #",
"# # #",
"## ##",
"#   #",

"#   #",
" # # ",
"  #  ",
" # # ",
"#   #",

"#   #",
" # # ",
"  #  ",
"  #  ",
"  #  ",

"#####",
"   # ",
"  #  ",
" #   ",
"#####",
};


 string period = "    #";
 string ex = "### #";
 
 void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
 
int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  string line;
  getline(cin, line);

  FOR(i, 0, 5) {
    bool hit = false;
    for(char c : line) {
      if(c == ' ') continue;
      if(hit) cout << ' ';

      if (c == '.') cout << period[i];
      else if(c == '!') cout << ex[i];
      else if(c != ' ') cout << word[(c - 'A')*5 + i];
      hit = true;
    } 
    cout << '\n';
  }

  return 0;
}
