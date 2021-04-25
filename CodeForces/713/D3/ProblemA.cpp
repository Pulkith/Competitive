#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int T;
    cin >> T;
    for(int a = 0; a < T; ++a) {
        int N;
        cin >> N;
        int n1, n2;
        cin >> n1 >> n2;
        int sm;
        if(n1 == n2){
            sm = n1;
            for(int i = 2; i < N; ++i) {
                int k;
                cin >> k;
                if(k != sm){
                    cout << (i+1) << endl;
                    int tmp;
                    for(int j = (i+1); j < N; ++j)
                        cin >> tmp;
                    break;
                }
            }
        }
        else {
            int n3;
            cin >> n3;
            if(n1 == n3)
                cout<<  2 << endl;
            if(n2 == n3)
                cout<<  1 << endl;
            int x = (N-3);
            int tmp;
            for(int i = 0; i < x; ++i)
                cin >> tmp;
        }
    }
}