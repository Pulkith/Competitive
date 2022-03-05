

#include <algorithm>
#include<bits/stdc++.h>
#include <vector>


using namespace std;

vector<int> calc(vector<int> a) {
  int N;
   // cin >> N;
  // vector<int> a(N);
  N = a.size();
  N *= 2;
  // for(int i = 0; i < N; ++i) cin >> a[i];

  vector<vector<int>> segs = {{}};
  
  for(int i = 0; i < N; ++i) {
    if(a[i] == (i+1)) {
      segs.back().push_back(a[i]);
      segs.push_back({});
    } else {
      segs.back().push_back(a[i]);
    }
  }
  segs.pop_back();
  int K = N;
  int sub = 0;
  // cout << K << '\n';
  vector<int> res;
  int nxt = 1;

  for(auto seg : segs) {
    for(auto& v : seg) v -= sub;
    vector<int> ans((int)seg.size()+1);
    ans[1] = nxt;

    set<int> srch;
    map<int, int> srch_val;

    for(int i = 0; i < seg.size(); ++i) {
        if(!ans[i+1]) {
          //find max index such that seg[index] < i
          ans[i+1] = nxt;
          auto lower = srch.lower_bound(i+1);
          if(lower != srch.begin()){
            --lower;
            ans[i+1] = max(ans[i+1], srch_val[*(lower)] + K + 1);
            cout << (i+sub+1) << " " << srch_val[*lower] << " " << nxt << " " << ans[i+1] << '\n';
          }
        }
        if(ans[seg[i]]) {

        } else {
          ans[seg[i]] = ans[i+1] + K;
        }

        srch.insert(seg[i]);
        srch_val[seg[i]] = ans[i+1];

        nxt = ans[i+1] + 1;
    }
    sub += (int)(seg.size());
    nxt += (K+1);
    for(int i = 1; i < ans.size(); ++i) res.push_back(ans[i]);
  }
  return res;
}
bool chk(vector<int> ans, vector<int> a) {
  int K = ans.size();
  
  for(int i = 0; i < ans.size(); ++i) {
    int j = i;
    while(j < ans.size() && ans[j] <= ans[i] + K) ++j;
    // cout << j << " " << a[i] << '\n';
    if(j != a[i]) return false;
  }

  return 1;
}

void run() {
  int x = 10;
  vector<int> n(x);
  for(int a = 0; a < x; ++a)
    for(int b = max(a, 1); b < x; ++b)
      for(int c = max(b, 2); c< x; ++c)
        for(int d = max(c, 3); d < x; ++d)
          for(int e = max(4, d); e < x; ++e)
            for(int f = max(5, e); f < x; ++f)
              for(int g = max(6, f); g < x; ++g)
                for(int h = max(7, g); h < x; ++h)
                  for(int i = max(8, h); i < x; ++i)
                    for(int j = max(9, j); j < x; ++j) {
                      n = {a+1, b+1, c+1, d+1, e+1, f+1, g+1, h+1, i+1, j+1};
                      auto rs = calc(n);
                      if(!chk(rs, n)) {
                        for(auto v : n) cout << v << " ";
                          cout << '\n';
                        for(auto v : rs)
                          cout << v << " ";
                        cout << '\n';
                        assert(0);
                      }
                  }
                }


int main () {
  // int T; cin >> T;
  // while(T--) {
  
  // }
  // run();
  vector<int> vv = {1,2,3,4,7,9,9,9,10,10};
  auto r = calc(vv);
  cout << "\n\n";
  for(auto v : vv)
    cout << v << " ";
  cout << '\n';
  for(auto v : r)
    cout << v << " ";
  cout << '\n';
}
