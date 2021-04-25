#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    int b[3][100000+1];
    for(int i = 1; i <= N; ++i) {
        int v;
        cin >> v;
        for(int j = 0; j < 3; ++j)
            b[j][i] = b[j][i-1];
        ++b[v-1][i];
    }
    for(int i = 0; i < Q; ++i) {
        int a, c;
        cin >> a >> c;
        for(int j  = 0; j < 3; ++j)
            cout << (b[j][c] - b[j][a-1]) << (j != 2 ? " " : "") ;
        cout << endl;
    }
}