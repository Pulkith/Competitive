#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = 0, b = 0;
        if((r1-l1) < (r2-l2)) {
            a = l1;
            b = (l2 == l1) ? (l1+1) : l2;
        } else {
            b = l2;
            a = (l2 == l1) ? (l1+1) : l1;
        }
        cout << a << " " << b << endl;
    }
}