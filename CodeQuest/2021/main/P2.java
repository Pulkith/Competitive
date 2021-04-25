import java.util.*;

public class P2  {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int T = Integer.parseInt(s.nextLine());
        while(T-- > 0) {
            String ss = s.nextLine();
            String split[] = ss.split(" ");
            int max = 0;
            for(String st : split){
                int in = Integer.parseInt(st);
                max = Math.max(max, in);
            }
            System.out.println(max);
        }
    }
}
