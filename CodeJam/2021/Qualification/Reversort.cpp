#include "std.h"

using namespace std;

void helper(int i, int j, int* a) {
    int x = i;
    int y = j;

    while(x <= y){
        swap(a[x], a[y]);
        x++;
        y--;
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long res = 0;
    for(int i = 0; i < n-1; ++i){
        int mI = n-1;
        int mid = INT_MAX;

        for(int j = n-1; j >= i; j--) {
            if(a[j] < mid){
                mid = a[j];
                mI = j; 
            }
        }
        helper(i, mI, a);
        res += mI-i+1;
    }
    cout << res << endl;
}
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cout << "Case #" << (i+1) << " ";
        solve();
    }
    
}