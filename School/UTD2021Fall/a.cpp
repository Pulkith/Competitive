/**
 * author: DespicableMonkey
 * created: 10.23.2021 10:49:44
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

long long a[1005];
long long tot[1005];
int main () {
    int N, M;
     cin >> N;
     FOR(i, 0, N) {
        cin >> a[i];
        tot[i] += a[i];
     }
     cin >> M;
     FOR(i, 0, M) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tot[v] += a[u];
        tot[u] += a[v];
     }
     long long minn = (10000000000);
     int ans = 0;
     for(int i = 0; i < N; ++i) {
        if(tot[i] < minn) {
            minn = tot[i];
            ans = i+1;
        }
     }
   cout << ans << '\n';
    return 0;
}

Scanner scan  = new Scanner(System.in);
int N = scan.nextInt();
long[] val = new long[N], total = new long[N];
for(int i = 0; i < N; ++i) {
   val[i] = scan.nextInt();
   total[i] += val[i];
}
int M = scan.nextInt();
for(int i = 0; i < M; i++) {
   int u = scan.nextInt(), v =scan.nextInt();
   total[u-1] += val[v-1];
   total[v-1] += val[u-1];
}
long min = 10000000000000, ans = 0;
for(int i = 0; i < N; ++i) {
   if(total[i] < min) {
      min = total[i];
      ans = i+1;
   }
}
System.out.println(ans);

