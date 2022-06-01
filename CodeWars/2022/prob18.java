import java.util.*;

public class prob18 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String ww = scan.nextLine().replace("[", "").replace("]", "");
    String[] chiper = ww.split(",");
    int N = chiper.length;
    String[] words = new String[N];
    for(int i = 0; i < N; ++i) 
      words[i] = scan.nextLine();
    String ans = "";
    for(int i = 0; i < N; ++i) {
      if(chiper[i].equals("0")) continue;
      String[] spl = chiper[i].split(";");
      int[] use = new int[words[i].length()+2];
      for(String c : spl) {
        if(c.indexOf("-") > -1 && c.split("-")[0].length() > 0) {
          int lo = Integer.parseInt(c.split("-")[0]);
          int hi = Integer.parseInt(c.split("-")[1]);
          use[lo-1]++;
          use[hi]--;
        } else {
          Integer k = Integer.parseInt(c);
          if(k > 0) {
            ++use[k-1];
            --use[k];
          } else {
            int index = words[i].length() + k + 1;
            ++use[index-1];
            --use[index];
          }
        }
      }

      for(int j = 0; j < words[i].length(); ++j){
        if(j > 0) use[j] += use[j-1];
        if(use[j] > 0)
          ans += words[i].charAt(j);
      }
    }
    System.out.println(ans);
  }
}