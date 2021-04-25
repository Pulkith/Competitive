#include <algorithm>
#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

class Help {
public:
    ll min = 0;
};
ll check(ll sR, ll sC, ll pos [][2], vector<ll>& order) {
    ll dist = abs(pos[order.at(0)][0] - sR) + abs(pos[order.at(0)][1] - sC);
    for (int i = 1; i < order.size(); i++) {
        dist += abs(pos[order.at(i)][0] - pos[order.at(i - 1)][0]) + abs(pos[order.at(i)][1] - pos[order.at(i - 1)][1]);
    }
    dist += abs(pos[order.at(order.size() - 1)][0] - sR) + abs(pos[order.at(order.size() - 1)][1] - sC);
    return dist;
}
 void search(Help &res, ll sR, ll sC, ll pos [][2], vector<ll>& options, vector<ll>& current) {
     if (options.empty()) {
         res.min = min(res.min, check(sR, sC, pos, current));
         return;
     }
     for (int i = 0; i < options.size(); i++) {
         ll n = options[i];
         options.erase(options.begin()+i);
         current.push_back(n);
         search(res, sR, sC, pos, options, current);
         current.erase(current.begin()+(current.size() - 1));
         options.insert(options.begin()+i, n);
     }
}
int main (){
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
            int t1, t2;
            cin >> t1 >> t2;
            int sR,sC;
            cin >> sR >> sC;
            int N;
            cin >> N;
            if (N == 0) {
                cout << "0" << endl;
                continue;
            }
            ll pos[N][2];
            for (int i = 0; i < N; i++) {
                int a, b;
                cin >> a >> b;
                pos[i][0] = a;
                pos[i][1] = b;
            }
            vector<ll> options;
            for (int i = 0; i < N; i++) {
                options.push_back(i);
            }
            Help res;
            res.min = 2e7;
            vector<ll> v;
            search(res, sR, sC, pos, options, v);
            cout << res.min << endl;
        }
    }
