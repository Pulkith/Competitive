#include <iostream>
#include <set>

using namespace std;
bool unique(string s) {
    set<char> se;
    for(int i = 0; i < s.size(); ++i)
        se.insert(s[i]);
    return s.size() == se.size();
}
int main(){
    int a,b;
    cin >> a >> b;
    if(to_string(a).size() > 10) cout << "-1";
    else {
        bool ok = false;
        int i;
        for(i = a; i <= b && !ok; ++i) {
            if(unique(to_string(i))) 
                ok = true;
        }
        cout << ((ok) ? i-1 : -1);
    }
}