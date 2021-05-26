#include<iostream>
#include<vector>
#include<algorithm>

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
    setIO("homework");
    //setIn("in1.txt");
    int N; cin >> N;

    vector<int> a(N);
    FOR(i, 0, N) cin >> a[i];

    int minn = min(a[N-1], a[N-2]);
    long long total = a[N-1] + a[N-2] - minn;
    double ans_average = total;
    vector<int> ans = {N-2};
    for(int i = N-3; i >= 1; --i) {
        if(a[i] < minn) {
            total += minn;
            total -= a[i];
            minn = a[i];
        } else
            total += a[i];
        double cur_total = (double)total / (N-i - 1);
        if(cur_total > ans_average ) {
            ans.clear();
            ans.push_back(i); 
            ans_average = cur_total;
        } else if(abs(cur_total - ans_average) < 0.000000000001) {
            ans.push_back(i);
        }

    }
    sort(ans.begin(), ans.end());
    FOR(i, 0, ans.size())
        cout << ans[i] << '\n';

    return 0;
}