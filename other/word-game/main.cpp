/**
 * author: DespicableMonkey
 * created: 07.05.2021 16:11:50
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sys/_types/_key_t.h>
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


struct WC_Helper {
public:
    void init(string user_key) {
        set_key(user_key);
    }

    void set_key(string key_try) {
        lower(key_try);
        if(verify_key(key_try))
            key = key_try; 
    }

    void set_count(int output_count_temp) {
        if(output_count_temp > 0)
            output_count = output_count_temp;
    }

    vector<string> read() {
        if(!verify_key()) return {};

        read_data(set_input());

        return objects;
    }

    void sort_words(string by = "length") {
        if(by == "") return;

        if(by == "length") {
            sort(objects.begin(), objects.end(), [&](string& l, string &r) -> bool {
                return sz(l) > sz(r);
            });
        }
        else if(by == "count") {

        } else if(by == "one-line") {

        } else 
            putr("Invalid Sort Option");
    }

    bool good_key() {
        return verify_key();
    }

    void output() {
        for(int i = 0; i < min(output_count, sz(objects)); ++i) {
            cout << objects[i] << ' ';
        }

        cout << "\n";
    }
private:
    const string dir = "/Users/despicablemonkey/Desktop/Competitive/other/word-game/database/";
    const string ext = ".txt";
    string key = "";
    int output_count = 5;
    vector<string> objects;

    void lower(std::string &s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }

    bool verify_key(string key_to_verify = "") {
        if(!sz(key_to_verify)) key_to_verify = key;
        if(sz(key_to_verify) != 3) return 0;
        for(char let : key_to_verify)
            if(let < 'a' || let > 'z')
                return 0;
        return 1;
    }

    void read_data(ifstream input) {
        objects.clear();
        string word;
        while(input >> word) {
           bool ok = 1;
           for(char cha : word)
               ok &= (cha >= 'a' && cha <= 'z');
           if(ok) objects.push_back(word);
        } 

        assert(objects.size());
        objects.pop_back();
    }

    ifstream set_input() {
        std::ifstream is(dir + key + ext);
        return is;
    }

};



void test_case() {
    cout << "Enter Key: ";
    fflush(stdout);
    string key; cin >> key;

    WC_Helper wch;
    wch.init(key);
    if(!wch.good_key())  putr("\nInvalid Key");
    wch.read();
    wch.sort_words();
    wch.output();

    
}

int main () {

    my_brain_hurts
    Test_Cases = 10000000;
    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
