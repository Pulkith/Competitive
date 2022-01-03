#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cassert>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define sz(x) (int)(x).size()

int K, M, N;
int cows[200005];
pair<int, int> grass[200005];

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> K >> M >> N;
  FOR(i, 0, K) {
    int u, v; cin >> u >> v;
    grass[i] = {u, v};
  }

  sort(grass, grass + K);

  FOR(i, 0, M) cin >> cows[i];
  sort(cows, cows+M);

  long long ans = 0;
  priority_queue<pair<long long, long long>> singles;
  multiset<long long> doubles;
  long long leftinterval = 0, rightinterval = 0;
  FOR(i, 0, K)
    if(grass[i].first < cows[0])
      leftinterval += grass[i].second;
  FOR(i, 0, K)
    if(grass[i].first > cows[M-1])
      rightinterval += grass[i].second;
  singles.push({leftinterval, -1}); singles.push({rightinterval, -1});

  FOR(i, 0, M-1) {
    int cow1 = cows[i];
    int cow2 = cows[i+1];
    int distance = (cow2 - cow1 + 1) / 2;
    long long maxx = 0;
    long long cur = 0;
    long long dble = 0;
    pair<int, int> p = {cow1, -1};
    auto upper = upper_bound(grass, grass + K, p);
    queue<pair<int, int>> interval;
    while(upper < (grass + K) && (*upper).first < cow2) {
      dble += (*upper).second;
      while(sz(interval) && interval.front().first + distance <= (*upper).first) {
        cur -= interval.front().second;
        interval.pop();
      }
      cur += (*upper).second;
      interval.push(*upper);
      maxx = max(maxx, cur);
      ++upper;
    }
    singles.push({maxx, dble});
    doubles.insert(dble);
  }

  FOR(i, 0, N) {
    if(!sz(singles) && !sz(doubles)) break;
    if(i == N - 1) {
      if(sz(singles)) ans += singles.size();
    } else {
      if(sz(singles) == 1) {
        assert(sz(doubles) == 1);
        ans += *(doubles.begin());
      } else {
        auto first = (singles.top()); singles.pop();
        auto second = singles.top();

        if((!sz(doubles)) || (first.first + second.first >= *(doubles.begin()))) {
          singles.pop();
          ans += first.first + second.first;
          if(first.second > -1) {
            doubles.erase(doubles.lower_bound(first.second));
            if(first.second - first.first > 0) singles.push({first.second - first.first, -1});
          }
          if(second.second > -1) {
            doubles.erase(doubles.lower_bound(second.second));
            if(second.second - second.first > 0) singles.push({second.second - second.first, -1});
          }
          ++i;
        } else {
          ans += *(doubles.begin());
          doubles.erase(doubles.begin());
          ++i;
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
