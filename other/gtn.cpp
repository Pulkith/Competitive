/**
 * author: DespicableMonkey
 * created: 05.26.2021 12:09:27
 * 
 * Potatoes FTW!
 **/ 

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>
#include <numeric> 
#include <cassert>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;


#define nl << '\n';

void ff(){fflush(stdout);}


inline namespace ExecTime {
    #define cur_t chrono::high_resolution_clock::now()
    auto _start_time = cur_t;
    bool use = 0;
    void use_clock() { use = 1; }
    void log_time(bool start = true) {
        if(use) {
            if(!start) {
                auto _stop_time = cur_t;
                auto duration = duration_cast<milliseconds>(_stop_time - _start_time);
                cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n'; 
            }
            else
                _start_time = cur_t;
        }
    }
}

void solve() {
    cout << "Max is: " ; ff();
    int mx;
    cin >> mx;
    int lo = 0, hi = mx;
    while(lo < hi) {
        int mid = (lo+hi) / 2;
        cout << mid nl
        ff();
        char c;
        cin >> c;
        if(c == 'h')
            hi = mid;
        else if(c == 'l')
            lo = mid+1;
        else if(c == 'd')
            return;
    }
}

int main () {

    #if LOCAL
        //setIn("in1.txt");
    #endif

    int T = 10000; 
    //cin >> T;

    use_clock();

    while(T--){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    log_time(0);

    return 0;
}