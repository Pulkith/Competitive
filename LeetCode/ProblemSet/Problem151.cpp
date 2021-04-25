#include "std.h"

using namespace std;

    string reverseWords(string s) {
        istringstream iss(s);
        string comp  =  "";
        vector<string> v;
        for(string s ; iss >> s;) {
            if(s.length() > 0) {
                v.push_back(s);
                
            }
        }
        reverse(v.begin(), v.end());
        for(string w : v)
            comp += w + " ";
        
        return comp.substr(0, comp.length() - 1);
    }