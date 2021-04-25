#include <iostream>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    int in = 0;
    char a[n];
    int x = 0;
    int offset = 0;
    for(int i = 0; i < n; ++i) {
        a[i] = (char)('a'+in);
        if(++in >= k)
            in = (++offset)%k;
    }
    for(int i = 0; i < n; ++i)
        cout << a[i];
}