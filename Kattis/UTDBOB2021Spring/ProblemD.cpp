#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
struct help{
    double left;
    double center;
    int index;

    bool operator < (help x) const {
        return left < x.left;
    }
};
 
int main(){
    int n,l;
    double r,w,x;
    while (cin >> n >> l >> w){
        help a[n];
        for (int i=0;i<n;i++){
            cin >> x >> r;
            double rq = pow(r, 2);
            double sur = pow(w,2 );
            sur /= 4.0;
            double p = sqrt(rq - sur);
            a[i].left = (r>= w/2) ? (x-p) : -1;
            a[i].center = (r>=w/2) ? (x+p) : -1;
            a[i].index = i;
        }
        double A = 0, B = l;
        vector<int> water;
        sort(a,a+n);
        int indexon = 0;
        int best = 0;
        bool ok = true;
        while (a[indexon].center< A && ok){
            indexon++;
            if (indexon == n) ok = false;
        }
        if (A == B && ok){
            if (a[indexon].left <= A && a[indexon].center >= A) water.push_back(a[indexon].index);
            else ok = false;
        }
        double large = 0;   
        while (A < B && ok){
            if (indexon == n){
                ok = false;
            } else {
            large = -1;
            best = -1;
            while (a[indexon].left <= A){
                if (a[indexon].center - A > large){
                    large = a[indexon].center - A;
                    best = indexon;
                }
                indexon++;
                if (indexon == n) break;
            }
            if (best == -1){
                ok = false;
                break;
            }
            water.push_back(a[best].index);
            A = a[best].center;
            }
        }
        ll x = water.size();
        cout << (ok ? x : -1) << endl;
    }

    return 0;
}