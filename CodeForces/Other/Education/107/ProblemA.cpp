#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int u = 0;
        while (N--) {
            int i;
            cin >> i;
            if(i == 1 || i == 3)
            ++u;
        }
        cout << (u) << endl;
        
    }
}