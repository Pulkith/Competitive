//STATIC Minimum Range Queries. O(NLogN + Q)
//Source: https://www.youtube.com/watch?v=0jWeUdxrGm4
//inclusive queries ( [a, b] ), 0-indexed

//works for min, max, gcd;
//doesnt work for sum(becuase of possible overlapping middle)

//ar[N][Log[N]]
//For every power of 2,x, x < N, compute seqeunces of size x
struct SparseTable {
  static const int MAX_N = 50005;
  static const int LOG = 18;
  int a[MAX_N];
  int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]

  int query(int L, int R) { // O(1) [L..R]
    int len = R - L + 1;
      int k = 31 - __builtin_clz(len); //bit trick to find log2(N)
    return min(m[L][k], m[R-(1<<k)+1][k]);
  }
  void calc() { // O(N*log(N))
    for(int k = 1; k < LOG; k++) {
      for(int i = 0; i + (1 << k) - 1 < MAX_N; i++) {
        m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
      }
    }
  }
  void set(int i, int val) {
    m[i][0] = val;
  }
};
