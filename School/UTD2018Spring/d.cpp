/**
 * author: DespicableMonkey
 * created: 10.22.2021 19:41:16
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

const int MX = 1000043;
// C++ program to find rank of an element
// and k-th smallest element.
 
const int MAX_VAL = 1000001;
 
/* Updates element at index 'i' of BIT. */
void update(int i, int add, vector<int>& BIT){
    while (i > 0 && i < BIT.size())
    {
        BIT[i] += add;
        i = i + (i & (-i));
    }
}
 
/* Returns cumulative sum of all elements of
   fenwick tree/BIT from start upto and
   including element at index 'i'. */
int sum(int i, vector<int>& BIT){
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i = i - (i & (-i));
    }
 
    return ans;
}
 
// Returns lower bound for k in BIT.
int findKthSmallest(int k, vector<int> &BIT){
    // Do binary search in BIT[] for given
    // value k.
    int l = 0;
    int h = BIT.size();
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= sum(mid, BIT))
            h = mid;
        else
            l = mid+1;
    }
 
    return l;
}
 
// Insert x into BIT. We basically increment
// rank of all elements greater than x.
void insertElement(int x, vector<int> &BIT){
    update(x, 1, BIT);
}
 
// Delete x from BIT. We basically decreases
// rank of all elements greater than x.
void deleteElement(int x, vector<int> &BIT){
    update(x, -1, BIT);
}
 
// Returns rank of element. We basically
// return sum of elements from start to
// index x.
int findRank(int x, vector<int> &BIT){
    return sum(x, BIT);
}

int main () {
    int T; cin >> T;
    while(T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> a(N), ans(Q);
        vector<vector<int>> q(Q);
        vector<int> BIT(MX);
        map<int, int> index;

        for(int i = 0; i < N; ++i){
             cin >> a[i];
             compress[i] = a[i];
        }
        for(int i = 0; i < Q; ++i) {
            cin >> q[i].first;
            q[i].second = i;
        }
        sort(compress.begin(), compress.end());
        sort(q.begin(), q.end());
        multiset<int> cur;
        for(int i = 0; i < N; ++i) {
            if(i > 0 && compress[i] == compress[i-1]) ++i;
            index[compress[i]] = i;
        }
        for(int i = 0; i < N; ++i)
            a[i] = index[a[i]];
        int curQ = 0;
        for(int i = 0; i < N; ++i) {
            insertElement(a[i], BIT);
            cur.insert(a[i]);
            while(i+1 == q[curQ].first) {
                auto lb = cur.lower_bound(a[i]);
                if(lb != cur.begin()) {
                    int e = *(--lb);
                    cout << findRank(e, BIT);
                } else cout << 0 << '\n';
                ans[q[curQ].second] = findRank(a[i], BIT);
                ++curQ;
            }
        }

        for(int i = 0; i < Q; ++i)
            cout << (i+1) << " " << ans[i] << '\n';

    }

    return 0;
}
