#include<bits/stdc++.h>

using namespace std;

//#if LOCAL
//    CP::ExecTime::use_clock();
//#endif
//
//#if LOCAL
//    CP::ExecTime::log_time(0);
//#endif


inline namespace CP {
    inline namespace ExecTime {
        #define cur_t std::chrono::high_resolution_clock::now() /* 100 mil =  ~1 second */
        inline auto __start_time = cur_t;
        inline bool use = 0;
        inline void use_clock() { use = 1; }
        inline void log_time(bool start = true) {
            if(use) {
                if(!start) {
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(cur_t - __start_time);
                    cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n';
                }
                else  __start_time = cur_t;
            }
        }
    }
}
