/**
 * author: DespicableMonkey
 * created: 06.25.2021 16:56:34
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

int cnt[2][3][100005];
int differs[100005];
int N;
void init(string a, string b) {
    N = (a).size();
    for(int i = 0; i < N; ++i)
        ++cnt[0][a[i] == 'A'? 0 : a[i] == 'T' ? 1 : 2][i],
        ++cnt[1][b[i] == 'A'? 0 : b[i] == 'T' ? 1 : 2][i],
        differs[i] = (a[i] != b[i]);
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 3; ++j)
            partial_sum(cnt[i][j], cnt[i][j] + N, cnt[i][j]);
    partial_sum(differs, differs + N, differs);
}
 
int get_distance(int x, int y) {
    vector<vector<int>> cnts(2, vector<int>(3));
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            cnts[i][j] = cnt[i][j][y] - (x == 0 ? 0 : cnt[i][j][x-1]);
        }
    }

    for(int i = 0; i < 3; ++i)
        if(cnts[0][i] != cnts[1][i])
            return -1;

    long long need = differs[y] - (x == 0 ? 0 : differs[x - 1]);

    return (need / 2 + !!(need&1));
}
 
int main() {
    init("ATCAATACAT", "TAAACATATC");
    cout << get_distance(0, 9);
    return 0;
}