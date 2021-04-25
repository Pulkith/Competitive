import java.util.*;
import java.io.*;
import java.awt.*;


public class Problem1 {
  public static void main(String[] args) throws Exception {
      Scanner s = new Scanner(new File("promote.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("promote.out")));
      int[][] arr = new int[4][2];
      for(int i = 0; i < 4; ++i) {
            arr[i][0] = s.nextInt();
            arr[i][1] = s.nextInt();
      }
      int[] res = new int[3];
      for(int i = 3; i > 0; --i) {
        int diff = arr[i][1] - arr[i][0];
        res[i-1] = diff;
        arr[i-1][1] += diff;
    }
    for(int i = 0; i < res.length; ++i)
        out.println(res[i]);
      out.close();
  }  
}
