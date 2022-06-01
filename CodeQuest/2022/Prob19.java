import java.util.*;

public class Prob19 {
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int T = Integer.parseInt(sc.nextLine());
      while(T -- > 0) {
        String w = sc.nextLine();
        String res = "";
        for(char c : w.toCharArray()) {
          String kk = Integer.toBinaryString(Character.getNumericValue(c)).substring(1);
          res += kk;
        }
        while(res.length() % 128 != 0) res += "1";

        long A = 792250721;
        long B = 683117105 ; 
        long C = 1215387974;
        long  D = 1767829900;
        for(int i = 0; i < 128 / 32; ++i) {
          String chunk = res.substring(0 + 32 * i, 0 + 32 * (i+1));
          long S = (B ^ D) & (C | (~B));
          S = A + S;
          S = S + Long.parseLong(chunk, 2);
          for(int j = 0; j < (i % 32); ++j) {
            long top = S & (1 << (31));
            S = S << 1;
            S += top;
          }
          A = D;
          D = C;
          C = B;
          B = S;
        }
        String re = Long.toBinaryString(A).substring(32) + Long.toBinaryString(B).substring(32) + Long.toBinaryString(C).substring(32) + Long.toBinaryString(D).substring(32);
        String fin = "";
        for(int i = 0; i < re.length() / 4; ++i) {
          String ss = re.substring(i * 4, (i+1) * 4);
          fin += Integer.toHexString(Integer.parseInt(ss, 2));
        }
        System.out.println(fin);
      }
  }
}