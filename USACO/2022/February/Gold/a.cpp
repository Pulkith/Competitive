#include<bits/stdc++.h>
using namespace std;
int N;
int g[20];
int BitsSetTable256[256];
void initialize(){
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
}
int countSetBits(int n){
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}
long long permanent(int len){
    long long ans = 0;
    vector<long long> solution(len+1);
    for(int matrix = 0; matrix < (1 << len); ++matrix) {
        long long product = 1;
        for(int i = 0; i < len; ++i)
            product *= countSetBits(g[i] & matrix);
        solution[len - countSetBits(matrix)] += product;
    }
    for(int i = 0; i < len; ++i){
        ans += solution[i] * (i & 1 ? -1 : 1);
    }
    return ans;
}
map<int, set<int>> likes;
map<int, int> newval;
int main()
{

    initialize();
    cin >> N;
    for(int i = 0; i < N; ++i) {
        bool ok = true;
        for(int j = 0; j < N; ++j) {
            int x; 
            cin >> x;
            if(ok) {
                likes[i+1].insert(x);
            }
            if(x == (i+1)) ok = false;
        }
    }

    int Q; cin >> Q;
    while(Q--) {
        string s; cin >> s;
        long long ans = 1;
        for(int lo = 0; lo < 2; ++lo) {
            char search = (lo ? 'H' : 'G');
            int c = 1;
            set<int> in;
            for(int i = 0; i < N; ++i) if(s[i] == search) {
                    in.insert(i + 1);
                    newval[c++] = i+1;
            }
            --c;
            for(int i = 0; i < c; ++i) {
                g[i] = 0;
                for(int j = 0; j < c; ++j)
                    g[i] += (likes[newval[i+1]].find(newval[j+1]) != likes[newval[i+1]].end() ? 1 : 0) << (c - j - 1);
            }   
            if(c >= 2)
                ans *= permanent(c);
        }
        cout << ans << '\n';
    }
}
