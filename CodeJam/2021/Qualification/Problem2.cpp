#include "std.h"

using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    string str;
    cin >> str;
    int cost = 0;
    
    int pre = 'Z';
    int len = str.length();
    for(int i = 0; i < len; ++i) {
        if(str[i] == 'C'){
            if(pre == 'J') {
                cost += y;
            }
            pre = 'C';
        }
        else if(str[i] == 'J'){
            if(pre == 'C') {
                cost += x;
            }
            pre = 'J';
        } 
          
        
    }
            cout << cost << endl;
}
int main() {
    int T;
    cin >> T;

    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}