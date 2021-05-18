#include <iostream>
#include <cmath>
using namespace std;
#define ll long long;
int main() {
    int T;
    cin >> T;
    while(T--) {
    long long N, M, X; 
    cin >> N >> M >> X;
    X--;
    long long  A = X%N, B = X/N;
    cout << A*M+B+1 << "\n";
    }
}