/**
 * author: DespicableMonkey
 * created: 10.23.2021 10:51:14
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

pair<int, int> a[100005];

int main () {
    int N, K;
    cin >> N >> K;
    FOR(i, 0, N) {
         cin >> a[i].first >> a[i].second;
         a[i].second += K;
    }
    sort(a, a+N);
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    FOR(i, 0, N) {
        ++cur;
        while(pq.size() && pq.top() < a[i].first) {
            --cur;
            pq.pop();
        }
        pq.push(a[i].second);
        ans = max(cur, ans);
    }   
    cout << ans << '\n';
    return 0;
}

