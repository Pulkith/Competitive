#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;
typedef long long ll;

int main(){
    int v[INF];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    ll sum = 0;
    for(int i = 0; i < INF; ++i)
        sum += v[i];
}