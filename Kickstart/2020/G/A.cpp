#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int a[100001] = {0};
    for(int i = s.size()-5; i >= 0; --i){
        a[i] = a[i+1];
        if(s.substr(i, 5) == "START")
            ++a[i];
    }
    int sum = 0;
    for(int i = 0; i < ((int)s.size()-4); ++i) {
        if(s.substr(i, 4) == "KICK")
            sum += a[i];
    }
    cout << sum << endl;
}
int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}