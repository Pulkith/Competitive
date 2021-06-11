#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int a[51] = {0};
    for(int i = 1; i <= N; ++i) {
        int j;
        cin >> j;
        if(a[j] == 0)
            a[j] = i;
    }
    for(int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        cout << a[q] << " ";
        for(int j = 0; j < 51; ++j)
            if(a[j] < a[q])
                ++a[j];
        a[q] = 1;
    }
}