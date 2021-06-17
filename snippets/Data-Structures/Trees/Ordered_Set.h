/**
 * author: DespicableMonkey
 * created: 06.15.2021 15:41:16
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


//Usage Example
int test() {
    int N, K;
    cin >> N >> K;

    ordered_set<int> rem;
    for(int i = 0; i < N; ++i) rem.insert(i+1);

    int cur = K % N;
    while(rem.size()) {
        //get the element at index cur
        int it = *rem.find_by_order(cur);
        cout << it << ' ';
        //erase element(not the index)
        rem.erase(it);
        if(sz(rem)) 
            cur = (cur+K)%(rem.size());
    }
    


    return 0;
}
