#include "std.h"

using namespace std;

    bool isPalindrome(string s) {
        for(int i = 0, j = s.length() - 1; i < j; ++i, j--) {
            char c = tolower(s[i]);
            char e = tolower(s[j]);
            
            if(!isalnum(c)) {
                ++j;
                continue;
            }if(!isalnum(e)) {
                --i;
                continue;
            }
            if(e != c)
                return false;
        }
        return true;
    }