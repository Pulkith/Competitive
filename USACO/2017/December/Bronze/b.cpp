#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

inline namespace FileIO {
	void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
    void setDefault() {
        	cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
    }
	void setIO(string s = "") {
        setDefault();
		cin.exceptions(cin.failbit); 
		if (s.size()) setIn(s+".in"), setOut(s+".out"); 
	}
    void setIO(string s, string t) {
        setDefault();
        setIn(s); 
        setOut(t);
    }
}

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

int main() {
   setIO("shuffle");

    int N; cin >> N;
    map<int, int> shuffle;
    FOR(i, 1, N+1) {
        int x; cin >> x;
        shuffle.insert({x, i});
    }
    vector<pair<int, string>> a;
    FOR(i, 1, N+1) {
        string s; cin >> s;
        a.push_back({i, s});
    }
    FOR(i, 0, 3) {
        FOR(j, 1, N+1)
            a[j-1].first = shuffle[j];

        sort(a.begin(), a.end());
    }

    for(auto [_,y] : a) 
        cout << y << '\n';


    return 0;
}