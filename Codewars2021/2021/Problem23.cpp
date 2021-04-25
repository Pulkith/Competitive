#include "std.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int max = -1;
    for(int i = 0; i < n; i++) {
        int j;
        cin >> j;
        v.push_back(j);
        max  = fmax(max, j);
    }
    int ajdMax = ((max+1)/2);

    for(int i = 0; i < n; ++i) {
        int j = v[i];
            string maj = "";
            int adj = (j+1);
            int dif = (max - v[i]) / 2;
            for(int a = 0; a < (dif + adj); ++a)
                maj += " ";
            for(int a = 0; a < j;++a)
                maj += "#";
            cout << maj << endl;

        for(int k = 0; k < j; ++k) {
            
        }
        cout << maj << endl;       
    }

    

}