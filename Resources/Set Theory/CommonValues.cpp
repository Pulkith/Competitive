#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i, a) for(int i = 0; i < a; ++i)
#define SORT(v1) sort(v1.begin(), v1.end())


int main() {

    
    
    vi v1 = {5,2,8,9,4};
    vi v2 = {3,2,9,5};

    SORT(v1);
    SORT(v2);
    int count = 0;
    for(int i = 0, j = 0; i < v1.size(), j < v2.size(); i++, j++) {
        if(v1[i] == v2[j])
            ++count;
        else if(v1[i] > v2[j])
            --i;
        else
            --j;
    }
    cout << count << endl;
    
}