#include "std.h"

using namespace std;

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<string>> map;
    map.insert({'2', {"a", "b", "c"}});
    map.insert({'3', {"d", "e", "f"}});
    map.insert({'4', {"g", "h", "i"}});
    map.insert({'5', {"j", "k", "l"}});
    map.insert({'6', {"m", "n", "o"}});
    map.insert({'7', {"p", "q", "r", "s"}});
    map.insert({'8', {"t", "u", "v"}});
    map.insert({'9', {"w", "x", "y", "z"}});
    char x[digits.length()+1];
    strcpy(x, digits.c_str()); 
    vector<string> res;
    for(char c : x) {
        if(map.find(c) != map.end()) {
            vector<string> v = map[c];
            int size = res.size();
            for(int i = 0; i < size; ++i ) {
             string pre = res[i];
                for(int j = 0; j < v.size(); ++j) {  
                    if(j == 0)
                        res[i] = res[i] + v[j];
                    else
                        res.push_back(pre + v[j]);
                 }            
            }
            if(res.size() == 0) {
                for(int i = 0; i < v.size(); ++i)
                    res.push_back(v[i]);
            }
        } 
    }
    return res;
}
//3 99 -1 -100

//[1,2,3,4,5,6,7]
//3

//[-1,-100,3,99]
//2