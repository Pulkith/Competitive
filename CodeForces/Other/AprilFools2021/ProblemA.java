import java.util.*;

public class ProblemA {
    public static void main(String args[]) {
       Scanner s = new Scanner(System.in);
       String str = s.nextLine();
       if(str.length() == 1 || str.length() == 2)
            System.out.println("YES");
       else {
        boolean fib = true;
        int prev1 = str.charAt(0), prev2 = str.charAt(1);
        for(int i = 2; i < str.length() && fib; ++i) {
            int cur = str.charAt(i);
            if((((prev1-65)+(prev2-65))%26 == (cur-65))){
                prev1 = prev2;
                prev2 = cur;
            } else {
                fib = false;
            }
        }
        System.out.println(fib ? "YES" : "NO");
       }
    }
}
