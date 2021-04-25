import java.util.*;
import java.io.*;

public class Problem1 {
  public static void main(String[] args) throws Exception {
      Scanner s = new Scanner(new File("paint.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
      int i1 = s.nextInt(), i2 = s.nextInt(), i3 = s.nextInt(), i4 = s.nextInt(); 
      if((i3 <= i2 && i1 <= i4) || (i1 <= i4 && i3 <= i2)) {
          out.println(Math.abs(Math.min(i1, i3) - Math.max(i2, i4)));
      } else {
          out.println(Math.abs(i2 - i1) + Math.abs(i4-i3));
      }

      out.close();
  }  
}
