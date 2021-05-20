#include <iostream>

using namespace std;
#define ll long long

ll gcf1(ll a, ll b) {
    if(b == 0) return a;
    else return gcf1(b, a%b);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        ll N;
        cin >> N;
        ll gcf = 1;
        ll fin = 0;
        while(gcf == 1) {
            ll div = N;
            ll sum = 0;
            while(div > 0) {
                sum += div%10;
                div /= 10;
            }
            gcf = gcf1(N, sum);
            fin = N++;
        }
        cout << fin << endl;
    }
}
