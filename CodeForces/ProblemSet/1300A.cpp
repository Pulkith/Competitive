#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int zeros = 0, sum = 0;
        while(N--) {
            int i;
            cin >> i;
            if (i == 0)
                ++zeros;
            sum += i;
        }
        cout << (zeros + ((sum+zeros == 0) ? 1 : 0)) << endl;
    }
}