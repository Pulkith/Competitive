#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

int N;
vector<double> X,Y,R, intervals;
vector<bool> dsorted;
vector<int> dex;

bool sort_by_second(int i, int j){ return intervals[i] < intervals[j]; }
double intersect(double x){
    dsorted.clear();  intervals.clear(); dex.clear();
    FOR(i, 0, N){
        double D = R[i]*R[i] - (X[i] - x) * (X[i] - x);
        if(D > 0){
            double y = Y[i] - sqrt(D);
            dsorted.push_back(1);  intervals.push_back(y); dex.push_back(sz(dex));
            y = Y[i] + sqrt(D);
            dsorted.push_back(0);
            intervals.push_back(y); dex.push_back(sz(dex));
        }
    }
    sort(dex.begin(), dex.end(), sort_by_second);
    double res = 0.0, prev = -123;
    int rem = 0;
    for(auto&i : dex){
        double y = intervals[i];
        if(rem > 0)res += y - prev;
        if(dsorted[i] == 1)rem++;
        if(dsorted[i] == 0)rem--;
        prev = y;
    }
    return res;
}

int main() {
    cin >> N;
    FOR(i,0,N){
        int x,y,r;  cin >> x >> y >> r;
        X.push_back(x); Y.push_back(y); R.push_back(r);
    }
    double Lt = -20.0,  Rt = 20.0,  recets = 1000000;
    double dx = (Rt-Lt) / recets;
    double ans = 0.0, prev = 0.0;
    for(int i = 1; i <= recets; i++){
        double x = Lt + dx * double(i); double f = intersect(x);
        ans += (f + prev) * dx / 2.0;
        prev = f;
    }
    cout << setprecision(9) << ans << "\n";
    return 0;
}

