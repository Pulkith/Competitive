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
    //setIO("measurement");
    setIn("in5.txt");
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
    map<int, int> cows;
    int cnt = 0;
    int maxx = 0;
    set<int> nums;
    for(auto [a,y] : mp) {
        if(y.second >= 0) {
            cows[y.first] += y.second;
            if(nums.find(y.first) == nums.end()) {
                if(cows[y.first] > maxx) {
                    nums.clear();
                    maxx = cows[y.first];
                }
                if(cows[y.first] == maxx) {
                    nums.insert(y.first);
                    ++cnt;
                }
            }
            else if(nums.find(y.first) != nums.end() && cows[y.first] > maxx ) {
                maxx = cows[y.first];
                if(nums.size() > 1)
                    ++cnt;
                nums.clear();
                nums.insert(y.first);
            }
        } else {
            cows[y.first] += y.second;
            if(nums.find(y.first) != nums.end() ) {
                nums.erase(y.first);
                if(nums.size() == 0) {
                    maxx = 0;
                    for(auto [a, b] : cows) {
                        if(b > maxx) {
                            maxx = b;
                            nums.clear();
                            nums.insert(a);
                        } else if(b==maxx) {
                             nums.insert(a);
                        }
                    }
                    if(nums.find(y.first) == nums.end() && nums.size() == 1 ||
                       nums.size() > 1) ++cnt;
                } else
                    ++cnt;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}