#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>


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
    setIO("measurement");
    // setIn("in51.txt");
    int N, G;
    cin >> N >> G;
    map<int, pair<int, int>> mp;
    FOR(i, 0, N) {
        int day, cow, change; string s;
        cin >> day >> cow >> s;
        if(s[0] == '+')
            change = stoi(s.substr(1));
        else
            change = -stoi(s.substr(1));
        mp.insert({day, {cow, change}});
    }   


    int cnt = 0;
    map<int, int, greater<int>> cnts;
    map<int, int> cows;
    for(auto [_, y] : mp) {
        bool ontop = false;
        int num = 0;
        if(cows.find(y.first) != cows.end()) {
            ontop = (cnts.size() > 0 && cows[y.first] == (*cnts.begin()).first);
            num = --cnts[cows[y.first]];
            if(num == 0) cnts.erase(cows[y.first]);
        }
        int topSize = (cnts.size() == 0 ? 0 : (*cnts.begin()).second);
        bool below = ((*cnts.begin()).second < 0);
        cows[y.first] += y.second;
        ++cnts[cows[y.first]];
        bool nowOntop = (cows[y.first] == (*cnts.begin()).first);
        int topS = (*cnts.begin()).second;
        if((y.second > 0) && (ontop && num > 0 || !ontop && nowOntop && ((*cnts.begin()).second == 1) || !ontop && nowOntop && topS != topSize || below && (*cnts.begin()).first > 0)||
            (y.second < 0) && (ontop && num > 0 || ontop && nowOntop || topS != topSize || !below && (*cnts.begin()).first < 0)) 
            ++cnt;
    }


    cout << cnt << '\n';
    return 0;
}