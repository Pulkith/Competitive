#include<iostream>
#include<map>

using namespace std;

int main() {
    int N, G; cin >> N >> G;
    map<int, pair<int, int>> mp;
    for(int i = 0; i < N; ++i) {
        int day, cow, change;
        string s;
        cin >> day >> cow >> s;
        if(s[0] == '-')
            change = -1;
        else
            change = 1;
        mp.insert({day, {cow, stoi(s.substr(1)) * change}});
    }
    for(auto [x, y] : mp )
        cout << x << " " << y.first << " " << y.second << '\n';
}