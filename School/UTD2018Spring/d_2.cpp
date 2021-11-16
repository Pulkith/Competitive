/**
 * author: DespicableMonkey
 * created: 10.22.2021 21:37:35
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int val = 0;
    int less = 0;
    Node* l = nullptr; Node* r = nullptr;
    Node(int v, int l) {
        val = v;
        less = l;
    }
};
Node* head = nullptr;
int add(int u) {
    if(head == nullptr) {
        Node c(u, 0);
        head = &c;
        return 0;
    } else {
        Node* cur = head;
        while(1) {
            if(u <= cur->val) {
                if(cur->l == nullptr) {
                    Node c(u, cur->val - 1);
                    cur->l = &c;
                    return c.val;
                } else {
                    cur = cur->l;
                }
            } else {
                if(cur->r == nullptr) {
                    Node c(u, cur->val + 1);
                    cur->r = &c;
                    return c.val;
                } else {
                    cur = cur->r;
                }
            }
        }
        return -1;
    }
}


int main () {
    int T; cin >> T;
    while(T--) {
        head = nullptr;
         int N, Q;
         cin >> N >> Q;
         vector<int> ans(N), a(N);
         for(int i = 0; i < N; ++i) cin >> a[i];
         for(int i = 0; i < N; ++i) {
            ans[i] = add(a[i]);
            cout << ans[i] << '\n';
         }
         // for(int i = 0; i < Q; ++i) {
         //    int q; cin >> q;
         //    cout << (i+1) << " " << ans[q-1] << '\n';
         // }
    }
}
