#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

char grid[51][51];
int rs[51][51], cs[51][51];

void test_case() {
  int N, K;
  cin >> N >> K;
  FOR(i, 0, N) 
    FOR(j, 0, N) 
    cin >> grid[i][j];
  long long res = 0;
  FOR(i, 0, N){
    int last = 0;
    FOR(j, 0, N)
      last = rs[i][j] = last + (grid[i][j] == 'H');
  }
  FOR(j, 0, N){
    int last = 0;
    FOR(i, 0, N)
      last = cs[i][j] = last + (grid[i][j] == 'H');
  }
  int M = N-1;
  res += (!cs[M][0] && !rs[M][M]);
  res += (!rs[0][M] && !cs[M][M]);
  if(K > 1) {
    FOR(i, 1, N-1) {
      res += (!rs[0][i]&&!cs[M][i]&&!(rs[M][M] - rs[M][i]));
    }
    FOR(i, 1, N-1) {
      res += (!cs[i][0]&&!rs[i][M]&&!(cs[M][M] - cs[i][M]));
    }
  }

  if(K > 2) {
    FOR(first, 1, N-1) {
      FOR(second, 1, N-1) {
        res += (!rs[0][first] && !cs[second][first]&&
               !(rs[second][M] - rs[second][first]) &&
               !(cs[M][M] - cs[second][M]));
      }
    }

    FOR(first, 1, N-1) {
      FOR(second, 1, N-1) {
        res += (!cs[first][0]&& !rs[first][second]&& 
                !(cs[M][second] - cs[first][second]) && 
                !(rs[M][M] - rs[M][second]));
      }
    }
  }

  cout << res << '\n';

}

int main () {
  int T; cin >> T;
  while(T --) {
    test_case();

  } 

  return 0;
}