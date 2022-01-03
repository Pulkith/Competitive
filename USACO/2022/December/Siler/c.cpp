#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>

using namespace std;
#define sz(x) (int)(x).size()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)
#define ll long long

int N, K;
pair<int, int> a[200005];
ll ans_a[10005];
ll ans_b[10005];

int nums[10005], nums2[10005];

int main () {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> K;
  FOR(i, 0, N) cin >> a[i].first >> a[i].second;
  sort(a, a+N);
  FOR(i, 0, N) ++nums[a[i].first];
  FOR(i, 0, N) ++nums2[a[i].second];

  FORE(i, 0, 2 * K) {
    FORE(v, 0, K) {
      if(v > i) break;
      int dif = i - v;
      if(dif == v) ans_a[i] += nums[v] + nums[v] * 1LL * (nums[v]-1);
      else ans_a[i] += nums[v] * 1LL * nums[dif];
    }
    FORE(v, 0, K) {
      if(v > i) break;
      int dif = i - v;
      if(dif == v) ans_b[i+1] += nums2[v] + nums2[v] * 1LL * (nums2[v] - 1);
      else ans_b[i+1] += nums2[v] * 1LL * nums2[dif];
    }
  }
  ll running = 0;

  FORE(i, 0, 2 * K) {
    running += ans_a[i] - ans_b[i];
     // cout << "["<< i << "]: " << running << '\n';
    printf("%lld\n", running);
  }

  return 0;
}
