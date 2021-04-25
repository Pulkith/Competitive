#include<algorithm>
#include<vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i  < 7; ++i){
        int c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] <<  " ";
    cout << (v[2] == (v[1] + v[0]) ? v[3] : v[2]);
}