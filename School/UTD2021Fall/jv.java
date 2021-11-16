import java.io.*;
import java.util.*;

public class jv {

  static Long[][] dp;
  static int N, W, H;
  static long MOD = (long)(1e9 + 7);

  public static void main(String[] args) throws IOException {
    Scanner scan = new Scanner(System.in);
    N = scan.nextInt(); W = scan.nextInt(); H = scan.nextInt(); 
    recurse();
  }
  static long dta(int w, int ribbon) {
    if (ribbon < 0) return 0;
    if (w > W) return 1;
    if (dp[w][ribbon] != null) return dp[w][ribbon];
    long scenes = 0L;
    for (int len = 0; len <= H; len++) scenes = (scenes + dta(w + 1, ribbon - len));
    return dp[w][ribbon] = scenes % MOD;
  }
  static void recurse() {
    dp = new Long[W + 1][N + 1];
    int squares = Math.min(W * H, N);
    int open = (squares / W ) + 1;
    System.out.println(((dta(1, N) - open) + MOD) % MOD);
  }
}