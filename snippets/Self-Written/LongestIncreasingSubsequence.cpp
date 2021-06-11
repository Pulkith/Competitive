#include "std.h"

using namespace std;

int main() {
    vector<int> v = {6,2,5,1,7,4,8,4}; 
    int a [v.size()];

    for(int i = 0; i < v.size(); ++i) {
        a[i] = 1;
        for(int k = 0; k < i; ++k) {
            if( v[k] < v[i])
                a[i] = fmax(a[i], a[k]+1);
        }
    }
    cout <<  a[v.size() - 1];
    
}