
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MX = 200086;
int K, M, N;
int Nhoj[MX];
pair<int, int> patches[MX];
ll res, tot1, tot2;
multiset<ll> fullintervals;
priority_queue<pair<ll, ll>> maxdis;
pair<int, int> placeholder = {0, -(10009)};

int main () {
  cin >> K >> M  >> N;
  for(int i = 0; i < K; ++i) {
    int loc, taste;
    cin >> loc >> taste;
    patches[i] = {loc, taste};
  }

  for(int i = 0; i < M;++i){
    int loc; cin >> loc;
    Nhoj[i] = loc;
  }

  sort(Nhoj, Nhoj + M);
  sort(patches, patches + K);

  for(int i = 0; i < K; i++) {
    if(patches[i].first <= Nhoj[0])
      tot1 += patches[i].second;
    if(patches[i].first >= Nhoj[M-1])
      tot2 += patches[i].second;
  } 
  maxdis.push({tot1, -1});
  maxdis.push({tot2, -1});
  for(int i = 1; i < M; i++) {
    int leftbound = Nhoj[i-1], rightbound = Nhoj[i];
    int intervallength = (rightbound - leftbound + 1) / 2;
    ll maxcantake = 0, currenttake = 0, sum = 0;
    placeholder.first = leftbound;
    auto curpatch = lower_bound(patches, patches + K, placeholder);

    queue<pair<ll, ll>> ininterval;
    while(curpatch < (patches + K) && (*curpatch).first < rightbound) {
      sum += (*curpatch).second;
      while(ininterval.size() && ininterval.front().first + intervallength <= (*curpatch).first) {
        currenttake -= ininterval.front().second;
        ininterval.pop();
      }
      currenttake += (*curpatch).second;
      maxcantake = max(maxcantake, currenttake);
      ininterval.push(*curpatch);
      curpatch++;
    }
    maxdis.push({maxcantake, sum});
    fullintervals.insert(sum);
  }

  for(int i = 0; i < N && (maxdis.size() || fullintervals.size()); ++i){
      if(i == N - 1) {
        if(maxdis.size())
          res += maxdis.top().first;
      } else if((int)maxdis.size() == 1) 
        res += *(fullintervals.begin());
      else {
        auto highest = maxdis.top();
        maxdis.pop();
        auto secHighest = maxdis.top();
        maxdis.pop();

        if((int)fullintervals.size() == 0 || (highest.first + secHighest.first >= *(fullintervals.begin()))) {
          res += highest.first + secHighest.first;
          for(int j = 0; j < 2; j++) {
            auto e = (j ? secHighest : highest);
            if(e.second >= 0) {
              fullintervals.erase(fullintervals.lower_bound(e.second));
              if(e.second - e.first >= 1)
                maxdis.push({e.second - e.first, -1});
            }
          }
        } else {
          res += *(fullintervals.begin());
          fullintervals.erase(fullintervals.begin());
          maxdis.push(highest);
          maxdis.push(secHighest);
        }


        ++i;
      }
  }


  cout << res << '\n';

  return 0;
}
