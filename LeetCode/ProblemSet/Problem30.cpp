#include "std.h"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        sort(words.begin(), words.end());
        
        vector<string> t;
        for(int i = 0; i < (s.length() - words[0].length() * words.size())+1; ++i ) {
            string sub = s.substr(i, words[0].length() * words.size());
            t.clear();
            for(int j = 0; j < sub.length(); j += words[0].length())
                t.push_back(sub.substr(j, words[0].length()));
            sort(t.begin(), t.end());
            if(t == words)
                v.push_back(i);
        }
        return v;
    }
};