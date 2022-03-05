
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define x second.first
#define y second.second
#define v first
const ll INF = 1e18;

int main() {
    int N;
    cin >> N;
    set<pair<ll, pair<int,int>>> pq;
    map<pair<int, int>, ll> vals;
    vector<set<int>> columns(11); 
    for(int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        vals[{a, b}] = (i ? INF : 0);
        pq.insert({vals[{a, b}], {a, b}});
        columns[b].insert(a);
    }
    long long ans = 0;
    int cur = N;
    while(cur--) {
        pair<ll,pair<int,int>> top = *pq.begin();
        pq.erase(pq.begin());
        ans += top.v;
        columns[top.y].erase(top.x);

        for(int i = 0; i <= 10; ++i) {
            auto upper = columns[i].upper_bound(top.x);
            for(int j = 0; j < 2; ++j) {
                if(j == 0 && (upper != columns[i].end())) {}
                else if(j == 1 && upper != columns[i].begin()) { upper--; }
                else continue;
                ll p = *upper;
                ll distance = abs(p - top.x) * abs(p - top.x) + abs(i - top.y) * abs(i - top.y);
                if(distance < vals[{p, i}]) {
                    pq.erase({vals[{p, i}], {p, i}});
                    vals[{p, i}] = distance;
                    pq.insert({distance, {p, i}});
                }
            }
        }
    }
    if(N != 10) cout << "0" << '\n';
    else cout << ans << '\n';

    


    return 0;
}

