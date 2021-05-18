#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n < 2020){
            cout << "NO" << endl;
        } else {
            int div = n / 2020;
            if(n % 2020 <= div) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}