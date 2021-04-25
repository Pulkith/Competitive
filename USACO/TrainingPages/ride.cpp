/*
ID: despicablemonkey
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define vi vector<int>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    string a, b;
    fin >> a >> b;
    int sum1 = 1, sum2 = 1;
    for(int i = 0; i < a.size(); ++i)
        sum1 *= (a[i] - 64);
    for(int i = 0; i < b.size(); ++i)
        sum2 *= (b[i] - 64);       
    fout << ((sum1%47 == sum2%47) ? "GO" : "STAY") << endl;


    return 0;
}