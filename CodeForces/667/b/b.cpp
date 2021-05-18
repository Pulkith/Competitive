#include <iostream>

using namespace std;
#define ll long long
ll s(ll a, ll b, ll x, ll y, ll n) {
    ll d = min(a-x, n);
    n -= d;
    a -= d;
    d = min(b-y, n);
    n -= d;
    b -= d;
    return a*b;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        cout << min(s(a,b,x,y,n), s(b,a,y,x,n)) << endl;
    }
}
