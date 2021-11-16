#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string t; cin >> t;

    set<pair<int, int>> s;

    set<int> imp[10];

    auto er_next = [&](auto it) {
        imp[it->second].erase(it->first);
    };
    auto er = [&](int i) {
        auto it = s.lower_bound(make_pair(i, -1));
        if (it == s.end() || it->first != i) return;
        er_next(it);
        if (it != s.begin()) er_next(prev(it));

        s.erase(it);
    };
    auto add_next = [&](auto it) {
        if (next(it) == s.end()) return;
        int y = next(it)->second;
        int x = it->second;
        if (y == (x + 1) % 10) {
            imp[x].insert(it->first);
        }
    };
    auto add = [&](int i, int x) {
        er(i);
        auto [it, _] = s.insert(make_pair(i, x));
        add_next(it);
        if (it != s.begin()) add_next(prev(it));
    };

    for (int i = 0; i < n; i++) {
        add(i, t[i] - '0');
    }

    while (1) {
        bool bad = 1;
        for (int i = 0; i < 10; i++) {
            while (sz(imp[i])) {
                int a = *imp[i].begin();
                auto it = s.lower_bound(make_pair(a, -1));
                int b = next(it)->first;

                int x = it->second;

                er(a), er(b);
                add(a, (x + 2) % 10);

                bad = 0;
            }
        }
        if (bad) break;
    }
    for (auto [_, c] : s) cout << c;
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
    	cout << "Case #" << i << ": ";
    	solve();
	}
}


