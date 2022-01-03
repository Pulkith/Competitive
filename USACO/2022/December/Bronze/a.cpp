#include<bits/stdc++.h>
using namespace std;
int N;
string s;
vector<int> Gs, Hs;
long long ans = 0;
int main () {
  cin >> N >> s;
  for(int i = 0; i < N; ++i){
    if(s[i] == 'G') Gs.push_back(i);
    else if(s[i] == 'H') Hs.push_back(i);
  }
  for(int k =0; k < 2; ++k) {
    auto& e = (k ? Gs : Hs);
    for(int i = 0; i < e.size(); ++i) {
      int pre = (i == 0 ? 0 : e[i-1] + 1), nxt = (i == (int)(e.size()) - 1 ? N - 1 : e[i+1] - 1), cur = e[i];
      if(pre + 2 <= cur) ans += (cur - pre - 1);
      if(cur + 2 <= nxt) ans += (nxt - cur - 1);
      if(pre + 2 <= nxt) ans += ((cur - pre) * 1LL * (nxt - cur));
    }
  }
  cout << ans << '\n';
}