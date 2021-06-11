#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Frac {
    ll x, y;
    Frac() {
        y = 1;
        x = 0;
    }
    Frac(ll _x, ll _y) : x(_x), y(_y){
        if(y < 0) {
            y = -y; x = -x;
        }
        ll d = gcd(abs(x), y);
        x /= d; y /= d;
    }
    Frac(ll a) {
        x = a; y = 1;
    }
    Frac operator + (const Frac & b) const {
        return Frac(x * b.y + y * b.x, y * b.y);
    }
    Frac operator - (const Frac & b) const {
        return Frac(x * b.y - y * b.x, y * b.y);
    }
    Frac operator * (const Frac & b) const {
        return Frac(x * b.x, y * b.y);
    }
    Frac operator / (const Frac & b) const {
        ll dx = gcd(x, b.x);
        ll dy = gcd(y, b.y);
        return Frac(x / dx * (b.y / dy), (y / dy) * (b.x / dx));
    }
    bool operator == (const Frac & b) const {
        return x * b.y == y * b.x;
    }
    bool operator != (const Frac & b) const {
        return x * b.y != y * b.x;
    }
    bool operator < (const Frac & b) const {
        return x * b.y < y * b.x;
    }
    bool operator > (const Frac & b) const {
        return x * b.y > y * b.x;
    }
    bool operator <= (const Frac & b) const {
        return x * b.y <= y * b.x;
    }
    bool operator >= (const Frac & b) const {
        return x * b.y >= y * b.x;
    }
    Frac operator - () const {
        return Frac(-x, y);
    }
 
    // friend string so_string(Frac f) {
    // 	return to_string(frac(f.x,f.y));
    // 	// return
    // 	// return ts(x)+"/"+ts(y)+c;
    // }
};