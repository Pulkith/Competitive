/**
 * author: DespicableMonkey
 * created: 07.05.2021 16:12:28
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
    #define debug_active 1
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int Test_Cases = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

inline namespace CP {
     inline namespace Output {
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
            #define debug_active 0
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return void(put(__output))
    }
    class IO { public:
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void Input(int __use_input = 0) {if(!!__use_input && debug_active){setIn("in"+to_string(__use_input)+".txt");}}
        IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
        IO* SetIO(string __s = "", string __t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(__t)) setIn(__s), setOut(__t);
            else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+5); //Check the limits idiot
int N;
vector<string> words;
void lower(std::string &s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }


void parse(string key) {
    string dir = "/Users/despicablemonkey/Desktop/Competitive/other/word-game/database/";
    dir += (key + ".txt");
    CP::IO().setOut(dir);
    int count = 0;
    for(auto word : words) {
        if(word.find(key) != string::npos){
            cout << word << '\n';
            ++count;
        }
    }

    cout << "Completed: " << key << " [" << count << " words found]";



}

int main () {
    //CP::IO().SetIO()->FastIO().Input(0);

    

    CP::IO().setIn("/Users/despicablemonkey/Desktop/Competitive/other/word-game/words.txt");
    string s;
    while(cin >> s) {
        lower(s);
        words.pb(s);
    }

    FOR(i, 0, 26) {
        FOR(j, 0, 26) {
            FOR(k, 0, 26) {
                string cur = "";
                cur += string(1, i + 'a');
                cur += string(1, j+ 'a');
                cur += string(1, k + 'a');
                parse(cur);
            }
        }
    }




    return 0;
}
