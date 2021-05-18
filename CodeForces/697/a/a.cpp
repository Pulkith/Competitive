#include <iostream>

using namespace std;

#define ll long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;
        while(N%2==0)
            N/=2;
        cout << (N>1 ? "YES":"NO") << endl;
    }
}