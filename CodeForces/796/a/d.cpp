/**
 * author: DespicableMonkey
 * created: 09.04.2021 21:54:15
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

    template<class T> struct Seg { // comb(ID,b) = b
        const T ID = (0); T comb(T l, T r) { return max(l, r); }
        int n; vector<T> seg;
        void init(int _n) { n = _n; seg.assign(2*n,ID); }
        void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
        void upd(int p, T val) { // set val at position p
            seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
        T query(int l, int r) { // min on interval [l, r]
            T ra = ID, rb = ID;
            for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
                if (l&1) ra = comb(ra,seg[l++]);
                if (r&1) rb = comb(seg[--r],rb);
            }
            return comb(ra,rb);
        }
    };

    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, int> highest;
        sort(properties.begin(), properties.end(), [&](vector<int>& l, vector<int>& r) -> bool {
            return l[0] < r[0];
        });
        for(int i = 0; i < properties.size();  ++i) {
            highest[properties[i][0]] = max(highest[properties[i][0]], i);
        }
        Seg<int> s;
        s.init(properties.size() + 1);
        for(int i = 0; i < properties.size(); ++i)
            s.upd(i + 1, properties[i][1]);
        int ans = 0;
        for(int i = 0; i < properties.size(); ++i) {
            auto grt = highest[properties[i][0]];
            if(grt == (int)(properties.size()) - 1) continue;
            int index_greatr = grt + 1;
            int res = s.query(index_greatr+1, properties.size());
            ans += s.query(index_greatr + 1, properties.size()) > properties[i][1];
        }
        
        return ans;
    }

    int main() {
        vector<vector<int>> tes;
        tes.push_back({5, 5});
        tes.push_back({6, 3});
        tes.push_back({3, 6});
        cout << numberOfWeakCharacters(tes);
    }
