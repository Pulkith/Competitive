#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
void solve() {
        int a,b,c;
        cin >> a >> b >> c;
        int amin = pow(10, a-1);
        int bmin = pow(10, b-1);
        for(int i = amin; a < amin*10-1; ++i) {
            for(int j = bmin; j < bmin*10-1; ++j) {
                if(to_string(gcd(i, j)).size()==c) {
                    cout << i << " " << j << endl;
                    return;
                }
            }
        }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}