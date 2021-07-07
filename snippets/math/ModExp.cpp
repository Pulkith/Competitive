 
long long Mexp(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res= (res * base) % mod;
          exp = exp >> 1;
          base = (base * base) % mod;
    }
    return res;
}