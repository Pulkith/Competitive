
#include<bits/stdc++.h>

using namespace std;

pair<int, int> win(vector<int>& l, vector<int>& r) {
  int lw = 0, rw = 0;

  for(int i =0; i < 4; ++i){
    for(int j = 0; j < 4; ++j){
      lw += l[i] > r[j];
      rw += r[i] > l[j];
    }
  }

  return {lw, rw};
}

void tcas() {
  vector<int> d1(4), d2(4), d3(4);
  for(int i = 0; i < 4; ++i) cin >> d1[i];
  for(int i = 0; i < 4; ++i) cin >> d2[i];

  auto r = win(d1, d2);
  if(r.first == r.second) {
    cout << "no" << '\n';
    return;
  }
  if(r.first < r.second) swap(d1, d2);

  for(int i = 1; i < 10; ++i)
    for(int j = 1; j < 10; ++j)
      for(int k = 1; k < 10; ++k)
        for(int z = 1; z < 10; ++z) {
          d3[0] = i;
          d3[1] = j;
          d3[2] = k;
          d3[3] = z;

          auto r1 = win(d2, d3);
          auto r2 = win(d3, d1);

          if(r1.first > r1.second && r2.first > r2.second) {
            cout << "yes" << '\n';
            return;
          }
          
        }
  cout << "no" << '\n';
}

int main () {
  int T; cin >> T;
  while(T -- ) {
   tcas();

  }
}
